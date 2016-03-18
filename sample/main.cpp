#include <QCoreApplication>
#include <signal.h>

#include "sample.h"

void handler(int) { QCoreApplication::quit(); }


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	signal(SIGINT, handler);

	Sample run;

	return a.exec();
}
