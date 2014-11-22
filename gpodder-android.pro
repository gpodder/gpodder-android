TEMPLATE = app

QT += qml quick multimedia

SOURCES += main.cpp

INCLUDEPATH += include src
DEPENDPATH += include src

HEADERS += src/gpodderandroid.h
SOURCES += src/gpodderandroid.cpp

# Automatically generated, containing gpodder source and QML files
RESOURCES += gpodder.qrc

# Deployment
x86 {
    target.path = /libs/x86
} else: armeabi-v7a {
    target.path = /libs/armeabi-v7a
} else {
    target.path = /libs/armeabi
}
INSTALLS += target

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += $$ANDROID_PACKAGE_SOURCE_DIR/AndroidManifest.xml
