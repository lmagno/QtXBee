#include "modemstatus.h"
#include "digimeshpacket.h"
#include <QDebug>

ModemStatus::ModemStatus() {
}

unsigned char ModemStatus::getStatus(){
	return status;
}

void ModemStatus::setStatus(unsigned char st) {
	status = st;
}

void ModemStatus::setFrameData(QByteArray data) {
	if (data.size() > 1) {
		setApiID(data[0]);
		setStatus(data[1]);
	}

}
