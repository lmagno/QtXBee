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


SOURCES += main.cpp \
	QXbee/QXbee.cpp \
    QXbee/XBeePacket/ATCommand.cpp \
    QXbee/XBeePacket/ATCommandRemote.cpp \
    QXbee/XBeePacket/ATCommandResponse.cpp \
    QXbee/XBeePacket/ATCommandResponseRemote.cpp \
    QXbee/XBeePacket/ModemStatus.cpp \
    QXbee/XBeePacket/NodeIdentificationIndicator.cpp \
    QXbee/XBeePacket/RXIndicator.cpp \
    QXbee/XBeePacket/RXIndicatorExplicit.cpp \
    QXbee/XBeePacket/TransmitStatus.cpp \
    QXbee/XBeePacket/TXRequest.cpp \
    QXbee/XBeePacket/TXRequestExplicit.cpp

HEADERS += \
	QXbee/QXbee.h \
    QXbee/XBeePacket/ATCommand.h \
    QXbee/XBeePacket/ATCommandQueue.h \
    QXbee/XBeePacket/ATCommandRemote.h \
    QXbee/XBeePacket/ATCommandResponse.h \
    QXbee/XBeePacket/ATCommandResponseRemote.h \
    QXbee/XBeePacket/ModemStatus.h \
    QXbee/XBeePacket/NodeIdentificationIndicator.h \
    QXbee/XBeePacket/RXIndicator.h \
    QXbee/XBeePacket/RXIndicatorExplicit.h \
    QXbee/XBeePacket/TransmitStatus.h \
    QXbee/XBeePacket/TXRequest.h \
    QXbee/XBeePacket/TXRequestExplicit.h \
    QXbee/XBeePacket/XBeeFrame.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
