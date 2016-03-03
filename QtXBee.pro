#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T12:15:45
#
#-------------------------------------------------

QT       += core 

greaterThan(QT_MAJOR_VERSION, 4): QT += serialport


QT       -= gui

TARGET = qtxbtest
CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += serialport

CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/QXbee
INCLUDEPATH += $$PWD/QXbee/QXbeeFrame

SOURCES += main.cpp \
	QXbee/QXbee.cpp \
	QXbee/XBeeFrame/ATCommand.cpp \
	QXbee/XBeeFrame/ATCommandRemote.cpp \
	QXbee/XBeeFrame/ATCommandResponse.cpp \
	QXbee/XBeeFrame/ATCommandResponseRemote.cpp \
	QXbee/XBeeFrame/ModemStatus.cpp \
	QXbee/XBeeFrame/NodeIdentificationIndicator.cpp \
	QXbee/XBeeFrame/RXIndicator.cpp \
	QXbee/XBeeFrame/RXIndicatorExplicit.cpp \
	QXbee/XBeeFrame/TransmitStatus.cpp \
	QXbee/XBeeFrame/TXRequest.cpp \
	QXbee/XBeeFrame/TXRequestExplicit.cpp

HEADERS += \
	QXbee/typedef.h \
	QXbee/QXbee.h \
	QXbee/XBeeFrame/ATCommand.h \
	QXbee/XBeeFrame/ATCommandQueue.h \
	QXbee/XBeeFrame/ATCommandRemote.h \
	QXbee/XBeeFrame/ATCommandResponse.h \
	QXbee/XBeeFrame/ATCommandResponseRemote.h \
	QXbee/XBeeFrame/ModemStatus.h \
	QXbee/XBeeFrame/NodeIdentificationIndicator.h \
	QXbee/XBeeFrame/RXIndicator.h \
	QXbee/XBeeFrame/RXIndicatorExplicit.h \
	QXbee/XBeeFrame/TransmitStatus.h \
	QXbee/XBeeFrame/TXRequest.h \
	QXbee/XBeeFrame/TXRequestExplicit.h \
	QXbee/XBeeFrame/XBeeFrame.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
