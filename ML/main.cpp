#include "ML.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ML ml;
	ml.show();
	return a.exec();
}
