#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include "channelselection.h"

int main(int argc, char *argv[])
{
    set_qt_environment();

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ChannelSelection channelSelection;

    // Expose the ChannelSelection model to QML
    engine.rootContext()->setContextProperty("channelSelectionModel", channelSelection.getProbeChannelsModel());

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
    const int totalRows = 10;
    for(uint i =0; i<totalRows; ++i){
        QList<QVariant> newRow;
        newRow << QString::number(i);
        newRow << "---";
        newRow << "---";
        newRow << "";
        channelSelection.getProbeChannelsModel()->addRow(newRow);
    }

    return app.exec();
}
