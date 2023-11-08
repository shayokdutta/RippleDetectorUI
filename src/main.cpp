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

    return app.exec();
}
