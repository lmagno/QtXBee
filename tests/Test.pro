#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T12:15:45
#
#-------------------------------------------------

QT       += core testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += serialport

QT       -= gui

TARGET = ../build/Test
OBJECTS_DIR = ../build/tests
MOC_DIR = ../build/tests

CONFIG -= app_bundle
CONFIG += console testcase
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): CONFIG += serialport

TEMPLATE = app

INCLUDEPATH += $$PWD/../src
INCLUDEPATH += $$PWD/../src/QXBeePacket
DEPENDPATH += $$PWD/../src

SOURCES +=  \
	testATCommand.cpp \
	testATCommandRemote.cpp \
	testATCommandResponse.cpp \
	testATCommandQueue.cpp \
	testATCommandResponseRemote.cpp \
	testModemStatus.cpp \
	testNodeIdentificationIndicator.cpp \
	testRXIndicator.cpp \
	testRXIndicatorExplicit.cpp \
	testTransmitStatus.cpp \
	testTXRequest.cpp \
	testTXRequestExplicit.cpp \
	main.cpp

HEADERS +=  \
	Autotest.h \
	testATCommand.h \
	testATCommandRemote.h \
	testATCommandResponse.h \
	testATCommandQueue.h \
	testATCommandResponseRemote.h \
	testModemStatus.h \
	testNodeIdentificationIndicator.h \
	testRXIndicator.h \
	testRXIndicatorExplicit.h \
	testTransmitStatus.h \
	testTXRequest.h \
	testTXRequestExplicit.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lQXBee
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lQXBee
else:unix: LIBS += -L$$OUT_PWD/../src/ -lQXBee
win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/libQXBee.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/libQXBee.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/QXBee.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/QXBee.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../src/libQXBee.a
