#include "ML.h"
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ML ml;
	ml.show();
	return a.exec();

	/*Table data = Table::fetch_table("C:\\Users\\roinr\\Desktop\\Admission_Predict.csv");
	LR2 lr(data, "Chance of Admit ");
	lr.train(1, 3000);
	cout <<  lr.get_r_squared() << endl;*/


	return 0;
}
