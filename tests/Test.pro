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
INCLUDEPATH += $$PWD/../src/QXBeePacket

SOURCES +=  main.cpp \
	testATCommand.cpp \
	../src/QXBee.cpp \
	../src/XBeePacket/ATCommand.cpp \
	../src/XBeePacket/ATCommandRemote.cpp \
	../src/XBeePacket/ATCommandResponse.cpp \
	../src/XBeePacket/ATCommandResponseRemote.cpp \
	../src/XBeePacket/ModemStatus.cpp \
	../src/XBeePacket/NodeIdentificationIndicator.cpp \
	../src/XBeePacket/RXIndicator.cpp \
	../src/XBeePacket/RXIndicatorExplicit.cpp \
	../src/XBeePacket/TransmitStatus.cpp \
	../src/XBeePacket/TXRequest.cpp \
	../src/XBeePacket/TXRequestExplicit.cpp \
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
	testTXRequestExplicit.cpp

HEADERS +=  Autotest.h \
	testATCommand.h \
	../src/typedef.h \
	../src/QXBee.h \
	../src/XBeePacket/ATCommand.h \
	../src/XBeePacket/ATCommandQueue.h \
	../src/XBeePacket/ATCommandRemote.h \
	../src/XBeePacket/ATCommandResponse.h \
	../src/XBeePacket/ATCommandResponseRemote.h \
	../src/XBeePacket/ModemStatus.h \
	../src/XBeePacket/NodeIdentificationIndicator.h \
	../src/XBeePacket/RXIndicator.h \
	../src/XBeePacket/RXIndicatorExplicit.h \
	../src/XBeePacket/TransmitStatus.h \
	../src/XBeePacket/TXRequest.h \
	../src/XBeePacket/TXRequestExplicit.h \
	../src/XBeePacket/XBeePacket.h \
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
