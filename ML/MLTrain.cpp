#include "MLTrain.h"
//#include <qstandarditemmodel.h>
//#include <qfiledialog.h>
//#include <qtextstream.h>
//#include <qfile.h>


QT_CHARTS_USE_NAMESPACE

MLTrain::MLTrain(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Train Parameters");
	ui.wMssg->hide();
	ui.wPredict->hide();
	ui.wClamp->hide();
}

Ui::Dialog MLTrain::getUi() {
	return this->ui;
}

QVector<QString> MLTrain::getColNames() {
	return this->colNames;
}

void MLTrain::showPredict() {

	ui.cbPreds->clear();
	for (auto pred : this->preds) //insert preds to combobox 
		ui.cbPreds->addItem(pred.c_str());

	ui.wPredict->show();
}

void MLTrain::showLinePlot() {
	/*vector<string> pred_names = table.getColNames();
	vector<vector<double>> pred_data = tab.data_trans.getMat();
	vector<double> resp_data = lr.response.getMat()[0];
	pred_names.erase(pred_names.begin() + Helper::find(pred_names,lr.response_str));
*/
	
	QChart *chart = new QChart;
	QLineSeries *series = new QLineSeries;
	series->setName(QString("Cost (MSE) vs Iteration"));
	//series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
	series->setColor(QColor(100,34,12));
	//series->setMarkerSize(10.0);
	QStringList list;
	for (int i = 0; i < lr.costValues.size(); i++) {
		series->append(i+1, lr.costValues[i]);
		/*list.append(QString(lr.costValues[i]));*/
	}
	chart->addSeries(series);
	chart->createDefaultAxes();
	chart->setDropShadowEnabled(false);
	chart->axisX()->setRange(0, lr.costValues.size());
	chart->axisY()->setRange(0, lr.costValues[0]);
	chart->legend()->setVisible(false);
	chart->setTitle("Cost (MSE) vs # Iterations");
	chart->axisX()->setTitleText("Iteration");
	chart->axisY()->setTitleText("Cost");

	
		//QChart *chart = new QChart();
		//chart->legend()->hide();
		//chart->addSeries(series);
		//chart->createDefaultAxes();
		//chart->setDropShadowEnabled(false);
		//chart->setTitle("Simple line chart example");
		this->chartView = new QChartView(chart,ui.wScatter);
		this->chartView->resize(ui.wScatter->width(), ui.wScatter->height());
		chartView->setRenderHint(QPainter::Antialiasing);
		//this->resize(900, 900);
		//layout->addWidget(chartView, 3, 0);
		//this->setLayout(layout);
		chartView->show();
}

void MLTrain::setTable(Table& table) {
	this->table = table;
}

void MLTrain::showThetaValues() {

	QString str = QString("%1 = ").arg(QString(lr.response_str.c_str())); // start equation
	this->preds = lr.getPreds(table.getColNames()); //get predictors names
	//QMessageBox::warning(this, "eee", QString("%1 , %2").arg(preds[0].c_str()).arg(preds[1].c_str()));
	QString theta;
	QString predictor;
	theta = QString::number(round(lr.theta.getMat()[0][0] * 100) / 100);
	str.append(theta);
	for (int i = 0; i < preds.size(); i++) {
		theta = QString::number(round(lr.theta.getMat()[0][i+1]*100) / 100);
		predictor = preds[i].c_str();
		//QMessageBox::warning(this, "eee", QString("%1").arg(preds[i].c_str()));
		if (i != 0 && i % 2 == 0)
			str.append("\n");
		str.append(" + ");
		str.append(theta);
		str.append("[" + predictor + "]");
		if (i == preds.size()-1)
			continue;
	}
	//QMessageBox::warning(this, "eee", QString("%1 %2").arg(lr.data_trans.getMeanC()[0]).arg(lr.data_trans.getMeanC()[1]));
	ui.lblMssg->setText(QString("Trained successfully!\ncost: %1 \n%2\nR^2 = %3").arg(lr.costValues.back()).arg(str).arg(lr.get_r_squared()));
	ui.wMssg->show();
}

void MLTrain::train() {
	this->lr = LR2(this->table, ui.cbResponse->currentText().toStdString());
	try {
		lr.train(ui.cbRate->currentText().toDouble(), ui.cbIter->currentText().toInt()); //if train succeed
		showThetaValues();
		showLinePlot();
		showPredict();
		predVals.clear();
	}
	catch (exception e) { ui.lblMssg->setText(QString("Train failed!\nTry lowering the learning rate.")); ui.lblMssg->show(); }
}

//SIGNALS

void MLTrain::on_btnPredict_clicked() {
	vector<double> vals;
	for (int i = 0; i < preds.size(); i++) {
		vals.push_back(predVals[preds[i].c_str()].toDouble());
		//QMessageBox::warning(this, "eee", QString("%1 , %2").arg(vals[0]).arg(vals[1]));
	}
	QString response = lr.response_str.c_str();
	double prediction = lr.predict(vals);
	if (ui.cbClamp->isChecked()) {
		prediction = std::min(prediction, ui.cbMax->value());
		prediction = std::max(prediction, ui.cbMin->value());
	}
	ui.lblMssg->setText(QString("%1 = %2").arg(response).arg(prediction));
}

void MLTrain::on_btnSet_clicked() {
	predVals[ui.cbPreds->currentText()] = ui.dsbPreds->value();
	if (predVals.size() == preds.size()) //if all preds were given a value
		ui.btnPredict->setEnabled(true);
}

void MLTrain::on_btnOk_clicked() {
		ui.lblMssg->setText("Building a linear model...");
		ui.wMssg->show();
		QMessageBox::warning(this, "Train", QString("Building your model"));
		train();
}

void MLTrain::on_btnCancel_clicked() {
	this->reject();
}

void MLTrain::on_cbClamp_stateChanged(int state) {
	if (state) {
		ui.wScatter->resize(941, 481);
		this->chartView->resize(ui.wScatter->width(), ui.wScatter->height());
		ui.wClamp->show();
	}
	else {
		ui.wClamp->hide();
		ui.wScatter->resize(1151, 481);
		this->chartView->resize(ui.wScatter->width(), ui.wScatter->height());
	}
}

