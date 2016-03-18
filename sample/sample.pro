QT       += core
greaterThan(QT_MAJOR_VERSION, 4): QT += serialport
QT       -= gui

CONFIG += c++11

TARGET = ../QtXBee
OBJECTS_DIR = ../build
MOC_DIR = ../build

CONFIG += console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += serialport

TEMPLATE = app

INCLUDEPATH += $$PWD/../src/QXBee
INCLUDEPATH += $$PWD/../src/QXBee/QXBeePacket
DEPENDPATH += $$PWD/../src/QXBee

SOURCES += main.cpp \
    sample.cpp

greaterThan(QT_MAJOR_VERSION, 4) {
LIBS            += \
				-L/usr/lib \
				-L/usr/local/lib \

} else {

LIBS            += \
				-L/usr/lib \
				-lQtSerialPort \
}


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../release/ -lQXBee
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../debug/ -lQXBee
else:unix: LIBS += -L$$OUT_PWD/../ -lQXBee
win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../release/libQXBee.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../debug/libQXBee.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../release/QXBee.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../debug/QXBee.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libQXBee.a

HEADERS += \
    sample.h
