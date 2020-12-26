#include "minesweeping.h"
#include "SingleApp.h"
//#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);

	SingleApp a(argc, argv, "MineSweeper");
	if(a.isRunning())
	{
		a.sendMessage("The program is running!");
		return 0;
	}

	MineSweeping w;
	QObject::connect(&a, SIGNAL(recvMsg(QString)), &w, SLOT(showWindow()));
	w.show();
	return a.exec();
}
