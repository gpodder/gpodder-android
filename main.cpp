#include <QGuiApplication>

#include <QQuickView>
#include <QQmlContext>
#include <QFontDatabase>

#include <QStandardPaths>
#include <QDir>

#include "org_gpodder_android_GPodderNative.h"
#include "gpodderandroid.h"


static GPodderAndroid *
g_android = NULL;


JNIEXPORT void JNICALL
Java_org_gpodder_android_GPodderNative_audioBecomingNoisy(JNIEnv *env, jclass clazz)
{
    if (g_android) {
        emit g_android->audioBecomingNoisy();
    }
}


int
main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Native <-> QML glue object
    g_android = new GPodderAndroid();

    // gPodder storage directory
    QString data(QDir(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)).filePath("gPodder"));
    qputenv("GPODDER_HOME", data.toUtf8());

    // gPodder QML UI fonts and themeing
    QFontDatabase::addApplicationFont(":/touch/icons/iconic_fill.ttf");
    QFontDatabase::addApplicationFont(":/touch/fonts/source-sans-pro.extralight.ttf");

    QQuickView view;
    view.rootContext()->setContextProperty("gpodderAndroid", g_android);
    view.setSource(QUrl("qrc:/touch/gpodder.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
