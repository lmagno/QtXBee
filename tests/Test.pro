#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T12:15:45
#
#-------------------------------------------------

QT       += core testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += serialport


QT       -= gui

TARGET = ../build/tests/Test
OBJECTS_DIR = ../build/tests
MOC_DIR = ../build/tests

CONFIG   += console testcase

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += serialport

CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../src
INCLUDEPATH += $$PWD/../src/QXbeeFrame

SOURCES +=  main.cpp \
            testATCommand.cpp \
        	../src/QXBee.cpp \
        	../src/XBeeFrame/ATCommand.cpp \
        	../src/XBeeFrame/ATCommandRemote.cpp \
        	../src/XBeeFrame/ATCommandResponse.cpp \
        	../src/XBeeFrame/ATCommandResponseRemote.cpp \
        	../src/XBeeFrame/ModemStatus.cpp \
        	../src/XBeeFrame/NodeIdentificationIndicator.cpp \
        	../src/XBeeFrame/RXIndicator.cpp \
        	../src/XBeeFrame/RXIndicatorExplicit.cpp \
        	../src/XBeeFrame/TransmitStatus.cpp \
        	../src/XBeeFrame/TXRequest.cpp \
        	../src/XBeeFrame/TXRequestExplicit.cpp \
    testATCommandRemote.cpp

HEADERS +=  Autotest.h \
            testATCommand.h \
        	../src/typedef.h \
        	../src/QXBee.h \
        	../src/XBeeFrame/ATCommand.h \
        	../src/XBeeFrame/ATCommandQueue.h \
        	../src/XBeeFrame/ATCommandRemote.h \
        	../src/XBeeFrame/ATCommandResponse.h \
        	../src/XBeeFrame/ATCommandResponseRemote.h \
        	../src/XBeeFrame/ModemStatus.h \
        	../src/XBeeFrame/NodeIdentificationIndicator.h \
        	../src/XBeeFrame/RXIndicator.h \
        	../src/XBeeFrame/RXIndicatorExplicit.h \
        	../src/XBeeFrame/TransmitStatus.h \
        	../src/XBeeFrame/TXRequest.h \
        	../src/XBeeFrame/TXRequestExplicit.h \
        	../src/XBeeFrame/XBeeFrame.h \
    testATCommandRemote.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
