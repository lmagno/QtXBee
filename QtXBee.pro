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
	QXbee/atcommand.cpp \
	QXbee/txrequest.cpp \
	QXbee/txrequestexplicit.cpp \
	QXbee/modemstatus.cpp \
	QXbee/transmitstatus.cpp \
	QXbee/rxindicator.cpp \
	QXbee/rxindicatorexplicit.cpp \
	QXbee/nodeidentificationindicator.cpp \
	QXbee/atcommandremote.cpp \
	QXbee/atcommandresponse.cpp \
	QXbee/atcommandresponseremote.cpp \
    QXbee/atcommandqueue.cpp

HEADERS += \
	QXbee/QXbee.h \
	QXbee/atcommand.h \
	QXbee/txrequest.h \
	QXbee/txrequestexplicit.h \
	QXbee/atcommandresponse.h \
	QXbee/modemstatus.h \
	QXbee/transmitstatus.h \
	QXbee/rxindicator.h \
	QXbee/rxindicatorexplicit.h \
	QXbee/nodeidentificationindicator.h \
	QXbee/atcommandremote.h \
	QXbee/xbeepacket.h \
	QXbee/atcommandresponseremote.h \
	QXbee/atcommandqueue.h

greaterThan(QT_MAJOR_VERSION, 4){

LIBS            += \
                -L/usr/lib \
                -L/usr/local/lib \

} else {

LIBS            += \
                -L/usr/lib \
                -lQtSerialPort \
}
