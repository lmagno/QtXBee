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
	QXbee/XBeePacket/atcommand.cpp \
	QXbee/XBeePacket/txrequest.cpp \
	QXbee/XBeePacket/txrequestexplicit.cpp \
	QXbee/XBeePacket/modemstatus.cpp \
	QXbee/XBeePacket/transmitstatus.cpp \
	QXbee/XBeePacket/rxindicator.cpp \
	QXbee/XBeePacket/rxindicatorexplicit.cpp \
	QXbee/XBeePacket/nodeidentificationindicator.cpp \
	QXbee/XBeePacket/atcommandremote.cpp \
	QXbee/XBeePacket/atcommandresponse.cpp \
	QXbee/XBeePacket/atcommandresponseremote.cpp \
	QXbee/XBeePacket/atcommandqueue.cpp

HEADERS += \
	QXbee/QXbee.h \
	QXbee/XBeePacket/atcommand.h \
	QXbee/XBeePacket/txrequest.h \
	QXbee/XBeePacket/txrequestexplicit.h \
	QXbee/XBeePacket/atcommandresponse.h \
	QXbee/XBeePacket/modemstatus.h \
	QXbee/XBeePacket/transmitstatus.h \
	QXbee/XBeePacket/rxindicator.h \
	QXbee/XBeePacket/rxindicatorexplicit.h \
	QXbee/XBeePacket/nodeidentificationindicator.h \
	QXbee/XBeePacket/atcommandremote.h \
	QXbee/XBeePacket/xbeepacket.h \
	QXbee/XBeePacket/atcommandresponseremote.h \
	QXbee/XBeePacket/atcommandqueue.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
