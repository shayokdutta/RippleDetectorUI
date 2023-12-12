#include "datainterface.h"

#include <iostream>
#include <QCoreApplication>
#include <QThread>

#ifdef _WIN32 // NeuropixelsOpenEphysIMECInterface**********************************
/**
 * @brief NeuropixelsOpenEphysIMECInterface::NeuropixelsOpenEphysIMECInterface
 * @param port
 * @param sharedMemName
 * @param IPAddr
 */
NeuropixelsOpenEphysIMECInterface::NeuropixelsOpenEphysIMECInterface(
    int port, const std::string& sharedMemName, std::string& IPAddr)
    : DataInterface(port, sharedMemName, IPAddr) {

    // open socket **********************************************************
    // Creating Messaging socket as a client
    ConnectSocket = INVALID_SOCKET;
    std::cout << "[RippleDetectorUIApp] Creating Messaging socket."<<std::endl;
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("[RippleDetectorUIApp] WSAStartup failed with error: %d\n", iResult);
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(serverIPAddress.c_str(), std::to_string(serverPort).c_str(), &hints, &result);
    if (iResult != 0) {
        std::cout << "[RippleDetectorUIApp] Error resolving server address and port."<<std::endl;
        WSACleanup();
        return;
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr!=NULL; ptr=ptr->ai_next){
        // Create a socket for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            //freeaddrinfo(result);
            WSACleanup();
            std::cout << "[RippleDetectorUIApp] Error creating socket to connect to server."<<std::endl;
            return;
        }

        // Connect to the server
        iResult = ::connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen); // winsock api connect function
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            std::cout << "[RippleDetectorUIApp] Error connecting to server."<<std::endl;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("[RippleDetectorUIApp] Unable to connect to server!\n");
        WSACleanup();
        return;
    }

    std::cout << "[RippleDetectorUIApp] Connected to messaging server!"<<std::endl;

    // Open the shared memory **********************************************************
    std::cout << "[RippleDetectorUIApp] Creating sharedmemory map."<<std::endl;
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

    std::cout << "[RippleDetectorUIApp] SharedMemoryFile opened!"<<std::endl;
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::~NeuropixelsOpenEphysIMECInterface
 */
NeuropixelsOpenEphysIMECInterface::~NeuropixelsOpenEphysIMECInterface() {
    // Close the listening socket
    if (ConnectSocket != INVALID_SOCKET) {
        closesocket(ConnectSocket);
    }

    // Clean up Winsock
    WSACleanup();

    std::cout << "[RippleDetectorUIApp] Message receiving socket closed!"<<std::endl;

    // Unmap the shared memory
    if (lpSharedMemory != NULL) {
        UnmapViewOfFile(lpSharedMemory);
    }

    // Close the shared memory handle
    if (hMapFile != NULL) {
        CloseHandle(hMapFile);
    }
    std::cout << "[RippleDetectorUIApp] SharedMemoryFile closed!"<<std::endl;
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::writeToSocket
 * @param message
 */
void NeuropixelsOpenEphysIMECInterface::writeToSocket(const std::string& msg) {
    int iResult = send(ConnectSocket, msg.c_str(), (int)strlen(msg.c_str()), 0);
    if (iResult == SOCKET_ERROR) {
        std::cout << "[RippleDetectorUIApp] Error: Sending message failed. Error code: " + std::to_string(WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return;
    }
    else {
        std::cout << "[RippleDetectorUIApp] Message sent successfully" << std::endl;
    }
}

/**
 * @brief toLowerCase: Function to convert string to lower case.
 * @param str
 * @return
 */
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}


/**
 * @brief NeuropixelsOpenEphysIMECInterface::readFromSocket
 * @return
 */
std::string NeuropixelsOpenEphysIMECInterface::readFromSocket() {

    if (ConnectSocket == INVALID_SOCKET) {
        WSACleanup();
        std::cout << "[RippleDetectorUIApp] Unable to connect to server."<<std::endl;
        return "Unable to connect to server";
    }

    char recvbuf[512];
    int recvbuflen = 512;
    std::string receivedMsg;
    int iResult;

    std::cout << "[RippleDetectorUIApp] Socket read thread instantiated at "  + serverIPAddress + ":" + std::to_string(serverPort) <<std::endl;

    // Receive until the peer closes the connection
    do {
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {

            receivedMsg = toLowerCase(std::string(recvbuf, iResult));
            std::cout << "[RippleDetectorUIApp] Msg received: " << receivedMsg << std::endl;


            // Exit the application if 'exit' message is received
            if (receivedMsg == "exit") {
                writeToSocket("exit"); // let the socket know we're also exiting so it stops listening thread.
                QCoreApplication::quit();
                break;
            }

            if(receivedMsg == "pause"){
                // pause data acq
            }
            else if(receivedMsg == "resume" || receivedMsg == "start"){
                // resume data acq
            }
            else{
                std::cout <<"[RippleDetectorUIApp] I don't know this request :P : " << receivedMsg<<std::endl;
            }

        }
        else if (iResult == 0)
            std::cout << "[RippleDetectorUIApp] Connection closed"<<std::endl;
        else
            std::cout << "[RippleDetectorUIApp] recv failed: " << WSAGetLastError()<<std::endl;
    } while (iResult > 0);

    // Cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    std::cout << "[RippleDetectorUIApp] Socket read thread returning..." <<std::endl;
    return receivedMsg;
}


/**
 * @brief NeuropixelsOpenEphysIMECInterface::readFromSharedMemory
 */
void NeuropixelsOpenEphysIMECInterface::readFromSharedMemory() {
    // Implement shared memory read logic
    std::cout << "[RippleDetectorUIApp] Shared memory read thread instantiated"<<std::endl;

    std::cout << "[RippleDetectorUIApp] Shared memory read thread returning..."<<std::endl;
}

/**
 * @brief writeToSharedMemory
 * @param message
 */
void NeuropixelsOpenEphysIMECInterface::writeToSharedMemory(const std::string& message){
    // Ensure the message size does not exceed the buffer size
    if (message.size() < (385 * MAXPACKETS)) {
        // Copy the message to the shared memory
        std::memcpy(lpSharedMemory, message.c_str(), message.size());
        // Clear the rest of the buffer. This is probably redundant but alas anything being written
        // from this client end should clear and reset the buffer
        std::memset(static_cast<char*>(lpSharedMemory) + message.size(), 0, (385 * MAXPACKETS) - message.size());
    } else {
        std::cerr << "[RippleDetectorUIApp] Error: Message size exceeds shared memory buffer size." << std::endl;
    }
}

/**
 * @brief NeuropixelsOpenEphysIMECInterface::processData
 */
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
#endif
