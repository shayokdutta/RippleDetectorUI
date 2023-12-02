#include "datainterface.h"

#include <iostream>
#include <QCoreApplication>
#include <QThread>

/**
 * @brief NeuropixelsOpenEphysIMECInterface::NeuropixelsOpenEphysIMECInterface
 * @param port
 * @param sharedMemName
 * @param IPAddr
 */
NeuropixelsOpenEphysIMECInterface::NeuropixelsOpenEphysIMECInterface(int port, const std::string& sharedMemName, std::string& IPAddr)
    : DataInterface(port, sharedMemName, IPAddr) {

    // open socket **********************************************************
    // Creating Messaging socket as a client
    std::cout << "\nCreating Messaging socket.";
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        // Handle error
        return;
    }

    struct addrinfo hints;
    struct addrinfo *result = NULL;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(serverIPAddress.c_str(), std::to_string(serverPort).c_str(), &hints, &result);
    if (iResult != 0) {
        std::cout << "\nError resolving server address and port.";
        WSACleanup();
        return;
    }

    // Create a socket for connecting to server
    SOCKET ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        std::cout << "\nError creating socket to connect to server.";
        return;
    }

    // Connect to the server
    iResult = ::connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen); // winsock api connect function
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        freeaddrinfo(result);
        WSACleanup();
        std::cout << "\nError connecting to server.";
        return;
    }

    freeaddrinfo(result);
    std::cout << "\nConnected to messaging server!";

    // Open the shared memory **********************************************************
    std::cout << "\nCreating sharedmemory map.";
    hMapFile = OpenFileMappingW(
        FILE_MAP_READ,   // Read access
        FALSE,           // Do not inherit the name
        std::wstring(sharedMemoryName.begin(), sharedMemoryName.end()).c_str()); // Name of the shared memory object

    if (hMapFile == NULL) {
        // Handle error
    }

    // Map the shared memory
    lpSharedMemory = MapViewOfFile(
        hMapFile,   // Handle to the mapped file object
        FILE_MAP_READ,   // Read access
        0,               // High-order DWORD of the file offset
        0,               // Low-order DWORD of the file offset
        385 * MAXPACKETS);  // Number of bytes to map

    if (lpSharedMemory == NULL) {
        CloseHandle(hMapFile);
        // Handle error
    }

    std::cout << "\nSharedMemoryFile opened!";
    // Additional initialization code...
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::~NeuropixelsOpenEphysIMECInterface
 */
NeuropixelsOpenEphysIMECInterface::~NeuropixelsOpenEphysIMECInterface() {
    // Close the listening socket
    if (ListenSocket != INVALID_SOCKET) {
        closesocket(ListenSocket);
    }

    // Clean up Winsock
    WSACleanup();

    std::cout << "\nMessage receiving socket closed!";

    // Unmap the shared memory
    if (lpSharedMemory != NULL) {
        UnmapViewOfFile(lpSharedMemory);
    }

    // Close the shared memory handle
    if (hMapFile != NULL) {
        CloseHandle(hMapFile);
    }
    std::cout << "\nSharedMemoryFile closed!";

    // Additional cleanup code...
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::writeToSocket
 *  when  might this even be needed?
 * @param message
 */
void NeuropixelsOpenEphysIMECInterface::writeToSocket(const std::string& message) {
    // Implement socket write logic
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::readFromSocket
 * @return
 */
std::string NeuropixelsOpenEphysIMECInterface::readFromSocket() {
    // Assuming serverIPAddress and serverPort are already set
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cout << "\nWSAStartup failed.";
        return "WSAStartup failed";
    }

    struct addrinfo *result = NULL, *ptr = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(serverIPAddress.c_str(), std::to_string(serverPort).c_str(), &hints, &result);
    if (iResult != 0) {
        WSACleanup();
        std::cout << "\ngetaddrinfo failed.";
        return "getaddrinfo failed";
    }

    SOCKET ClientSocket = INVALID_SOCKET;
    ptr = result;

    // Attempt to connect to the first address returned by the call to getaddrinfo
    ClientSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ClientSocket == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        std::cout << "\nError at socket().";
        return "Error at socket()";
    }

    // Connect to server
    iResult = ::connect(ClientSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ClientSocket);
        ClientSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (ClientSocket == INVALID_SOCKET) {
        WSACleanup();
        std::cout << "\nUnable to connect to server.";
        return "Unable to connect to server";
    }

    char recvbuf[512];
    int recvbuflen = 512;
    std::string receivedMsg;

    // Receive until the peer closes the connection
    do {
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            receivedMsg = std::string(recvbuf, iResult);
            std::cout << "\nBytes received: " << iResult;

            // Exit the application if 'exit' message is received
            if (receivedMsg == "exit") {
                QCoreApplication::quit();
                break;
            }
        }
        else if (iResult == 0)
            std::cout << "\nConnection closed";
        else
            std::cout << "\nrecv failed: " << WSAGetLastError();
    } while (iResult > 0);

    // Cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return receivedMsg;
}


/**
 * @brief NeuropixelsOpenEphysIMECInterface::readFromSharedMemory
 */
void NeuropixelsOpenEphysIMECInterface::readFromSharedMemory() {
    // Implement shared memory read logic
    std::cout << "\nShared memory read thread instantiated";
}


void NeuropixelsOpenEphysIMECInterface::processData() {

    // Thread for reading from socket
    QThread* socketThread = QThread::create([this]{
        this->readFromSocket();
    });

    // Thread for reading from shared memory
    QThread* sharedMemoryThread = QThread::create([this]{
        this->readFromSharedMemory();
    });

    // Connect thread finished signals to delete them after execution
    connect(socketThread, &QThread::finished, socketThread, &QThread::deleteLater);
    connect(sharedMemoryThread, &QThread::finished, sharedMemoryThread, &QThread::deleteLater);

    // Start the threads
    socketThread->start();
    sharedMemoryThread->start();
}

