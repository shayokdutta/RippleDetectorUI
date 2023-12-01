#include "datainterface.h"

#ifdef _WIN32
// Include necessary headers for Windows socket programming
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h> // Ensure Windows API is included for HANDLE and LPVOID
#endif

#include <iostream>
#include <QCoreApplication>

/**
 * @brief NeuropixelsOpenEphysIMECInterface::NeuropixelsOpenEphysIMECInterface
 * @param port
 * @param sharedMemName
 * @param IPAddr
 */
NeuropixelsOpenEphysIMECInterface::NeuropixelsOpenEphysIMECInterface(int port, const std::string& sharedMemName, std::string& IPAddr)
    : DataInterface(port, sharedMemName, IPAddr) {

    // open socket **********************************************************
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
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(serverIPAddress.c_str(), std::to_string(serverPort).c_str(), &hints, &result);
    if (iResult != 0) {
        WSACleanup();
        return;
    }

    // Create a socket for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ListenSocket);
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    std::cout << "\nMessage receiving socket opened!";

    // Open the shared memory **********************************************************
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
    SOCKET ClientSocket = INVALID_SOCKET;

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        closesocket(ListenSocket);
        WSACleanup();
        return "Error accepting connection";
    }

    // Receive data until the client shuts down the connection
    char recvbuf[512];
    int iResult, recvbuflen = 512;
    std::string receivedMsg;

    do {
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            receivedMsg = std::string(recvbuf, iResult);
            if (receivedMsg == "exit") {
                QCoreApplication::quit(); // Exit the Qt application
                break;
            }
            // Handle other messages if needed
        } else if (iResult == 0) {
            // Connection closing...
        } else {
            // Error in recv
        }
    } while (iResult > 0);

    // Shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        closesocket(ClientSocket);
        WSACleanup();
        return "Error in shutdown";
    }

    // Cleanup
    closesocket(ClientSocket);
    return receivedMsg; // Return the received message
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::readFromSharedMemory
 */
void NeuropixelsOpenEphysIMECInterface::readFromSharedMemory() {
    // Implement shared memory read logic
}


void NeuropixelsOpenEphysIMECInterface::processData() {
    // Implementation of processData
    // ...
    while (true) {
        std::string message = readFromSocket();
        // Process the message
        // Read from shared memory if necessary
    }
}

// Additional methods specific to Neuropixels and IMEC can be implemented here
