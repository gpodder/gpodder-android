#include <QGuiApplication>

#include <QQuickView>
#include <QFontDatabase>

#include <QStandardPaths>
#include <QDir>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // gPodder storage directory
    QString data(QDir(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)).filePath("gPodder"));
    qputenv("GPODDER_HOME", data.toUtf8());

    // gPodder QML UI fonts and themeing
    QFontDatabase::addApplicationFont(":/touch/icons/iconic_fill.ttf");
    QFontDatabase::addApplicationFont(":/touch/fonts/source-sans-pro.extralight.ttf");

    QQuickView view;
    view.setSource(QUrl("qrc:/touch/gpodder.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
