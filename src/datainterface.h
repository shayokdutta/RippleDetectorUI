#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h> // Ensure Windows API is included for HANDLE and LPVOID
#pragma comment(lib, "Ws2_32.lib")
#endif

#include <QObject>
#include <string>

// Abstract base class
class DataInterface : public QObject {
    Q_OBJECT
public:
    DataInterface(int port, const std::string& sharedMemName, std::string& IPAddr)
        : serverPort(port), sharedMemoryName(sharedMemName), serverIPAddress(IPAddr) {}

    virtual ~DataInterface() {}

    virtual void writeToSocket(const std::string& message) = 0;
    virtual std::string readFromSocket() = 0;
    virtual void readFromSharedMemory() = 0;

public slots:
    virtual void processData() = 0; // Define this as a slot in your derived classes

signals:
    void finished(); // Signal to indicate the thread can be stopped

protected:
    std::string serverIPAddress;
    int serverPort;
    std::string sharedMemoryName;
};

// Derived class
class NeuropixelsOpenEphysIMECInterface : public DataInterface {
    Q_OBJECT
#define MAXPACKETS 64 // from neuropixels api

public:
    NeuropixelsOpenEphysIMECInterface(int port, const std::string& sharedMemName, std::string& IPAddr);
    ~NeuropixelsOpenEphysIMECInterface() override;

    void writeToSocket(const std::string& msg) override;
    std::string readFromSocket() override;
    void readFromSharedMemory() override;

    // Additional methods specific to Neuropixels/IMEC can be added here

public slots:
           void processData() override;

private: // Private members specific to Neuropixels/IMEC interface
    SOCKET ConnectSocket;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;


    HANDLE hMapFile; // Handle for the shared memory
    LPVOID lpSharedMemory; // Pointer to the mapped shared memory
};

#endif // DATAINTERFACE_H
