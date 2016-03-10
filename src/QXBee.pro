#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T12:15:45
#
#-------------------------------------------------

QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += serialport


QT       -= gui

TARGET = ../QXBee
OBJECTS_DIR = ../build
MOC_DIR = ../build

CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += serialport

CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/QXBeePacket

SOURCES += \
	main.cpp \
	QXBee.cpp \
	XBeePacket/ATCommand.cpp \
	XBeePacket/ATCommandRemote.cpp \
	XBeePacket/ATCommandResponse.cpp \
	XBeePacket/ATCommandResponseRemote.cpp \
	XBeePacket/ModemStatus.cpp \
	XBeePacket/NodeIdentificationIndicator.cpp \
	XBeePacket/RXIndicator.cpp \
	XBeePacket/RXIndicatorExplicit.cpp \
	XBeePacket/TransmitStatus.cpp \
	XBeePacket/TXRequest.cpp \
	XBeePacket/TXRequestExplicit.cpp

HEADERS += \
	typedef.h \
	QXBee.h \
	XBeePacket/ATCommand.h \
	XBeePacket/ATCommandQueue.h \
	XBeePacket/ATCommandRemote.h \
	XBeePacket/ATCommandResponse.h \
	XBeePacket/ATCommandResponseRemote.h \
	XBeePacket/ModemStatus.h \
	XBeePacket/NodeIdentificationIndicator.h \
	XBeePacket/RXIndicator.h \
	XBeePacket/RXIndicatorExplicit.h \
	XBeePacket/TransmitStatus.h \
	XBeePacket/TXRequest.h \
	XBeePacket/TXRequestExplicit.h \
	XBeePacket/XBeePacket.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
