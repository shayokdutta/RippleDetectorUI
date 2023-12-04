#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <cstdlib>
#include <iostream>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#endif


#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include "channelselection.h"
#include "stimulationhandler.h"
#include "datainterface.h"

int main(int argc, char *argv[])
{

#ifdef _WIN32
    if (AttachConsole(ATTACH_PARENT_PROCESS)) {
        FILE* fp;
        freopen_s(&fp, "CONOUT$", "w", stdout);
        freopen_s(&fp, "CONIN$", "r", stdin);
    }
#endif


    std::cout << "[RippleDetectorUIApp] We're in!"<<std::endl;
    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ChannelSelection channelSelection; DataInterface* dataInterfacePtr = NULL;

    StimulationHandler stimHandler(&channelSelection, dataInterfacePtr);

    // Expose the ChannelSelection model to QML
    engine.rootContext()->setContextProperty("channelSelectionModel", channelSelection.getProbeChannelsModel());
    engine.rootContext()->setContextProperty("CheckBoxStateRole", ChannelDataTable::checkBoxStateRole());
    const QUrl url(QStringLiteral("qrc:/qt/qml/Main/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    /* read in number of rows we need in the channel selection table somehow */
    uint totalRows = 10;
    std::string sharedMemoryName;
    std::string serverIPAddress;
    int serverPort = -1;

    // basically these will be the command line args that are required!
    // I should probably handle some error checking either or this end or the RippleDetectorInterface end
    if(argc > 4){

        totalRows = std::atoi(argv[2]);

        sharedMemoryName = argv[3];
        serverIPAddress = argv[4];
        serverPort = std::atoi(argv[5]);

        std::cout << "[RippleDetectorUIApp] numChannels: " << totalRows<<std::endl;
        std::cout << "[RippleDetectorUIApp] sharedMemoryName: " << sharedMemoryName<<std::endl;
        std::cout << "[RippleDetectorUIApp] serverIPAddress: " << serverIPAddress<<std::endl;
        std::cout << "[RippleDetectorUIApp] serverPort: " << serverPort<<std::endl;

        if(std::strcmp("WindowsOpenEphysIMECNPXIe",argv[1])==0){
            #ifdef _WIN32
            dataInterfacePtr = new NeuropixelsOpenEphysIMECInterface(serverPort, sharedMemoryName, serverIPAddress);
            // Start processing data (listening to socket and reading from shared memory)
            static_cast<NeuropixelsOpenEphysIMECInterface*>(dataInterfacePtr)->processData();
            #endif
        }

        if (totalRows <= 0) {
            totalRows = 10; // Fallback to default if the input is invalid
        }
    }
    for(uint i =0; i<totalRows; ++i){
        QList<QVariant> newRow;
        newRow << QString::number(i);
        newRow << "---";
        newRow << "---";
        newRow << false;
        newRow << false;
        channelSelection.getProbeChannelsModel()->addRow(newRow);
    }

    return app.exec();
}
