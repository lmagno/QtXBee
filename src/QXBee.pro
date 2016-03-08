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
INCLUDEPATH += $$PWD/QXBeeFrame

SOURCES += \
	main.cpp \
	QXBee.cpp \
	XBeeFrame/ATCommand.cpp \
	XBeeFrame/ATCommandRemote.cpp \
	XBeeFrame/ATCommandResponse.cpp \
	XBeeFrame/ATCommandResponseRemote.cpp \
	XBeeFrame/ModemStatus.cpp \
	XBeeFrame/NodeIdentificationIndicator.cpp \
	XBeeFrame/RXIndicator.cpp \
	XBeeFrame/RXIndicatorExplicit.cpp \
	XBeeFrame/TransmitStatus.cpp \
	XBeeFrame/TXRequest.cpp \
	XBeeFrame/TXRequestExplicit.cpp

HEADERS += \
	typedef.h \
	QXBee.h \
	XBeeFrame/ATCommand.h \
	XBeeFrame/ATCommandQueue.h \
	XBeeFrame/ATCommandRemote.h \
	XBeeFrame/ATCommandResponse.h \
	XBeeFrame/ATCommandResponseRemote.h \
	XBeeFrame/ModemStatus.h \
	XBeeFrame/NodeIdentificationIndicator.h \
	XBeeFrame/RXIndicator.h \
	XBeeFrame/RXIndicatorExplicit.h \
	XBeeFrame/TransmitStatus.h \
	XBeeFrame/TXRequest.h \
	XBeeFrame/TXRequestExplicit.h \
	XBeeFrame/XBeeFrame.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
