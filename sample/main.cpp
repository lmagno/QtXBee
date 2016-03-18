#include <QCoreApplication>
#include <signal.h>

#include "Sample.h"

void handler(int) { QCoreApplication::quit(); }


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	signal(SIGINT, handler);

	Sample run(0);

	return a.exec();
}
