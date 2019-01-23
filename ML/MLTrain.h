#pragma once
#include <QtWidgets/qdialog.h>
#include "ui_MLTrain.h"
#include <QtCharts>
#include "LR2.h"
#include "Matrix.h"
#include "chartview.h"

#ifndef MLTRAIN_H
#define MLTRAIN_H



class MLTrain : public QDialog
{
	Q_OBJECT;

public:
	MLTrain(QWidget *parent = Q_NULLPTR);
	Ui::Dialog getUi();
	QVector<QString> getColNames();
	void showLinePlot();
	void setTable(Table& table);
	void showThetaValues();
	void showPredict();

	//int getResponseIdx();

private:
	Ui::Dialog ui;
	LR2 lr;
	QStringList pred_names;
	//Data data;
	Table table;
	QVector<QString> colNames;
	QMap<int, QLabel> lblMap;
	QMap<int, QDoubleSpinBox> dsbMap;
	QMap<QString, QVariant> predVals;
	vector<string> preds;

private slots:
	
	void on_btnOk_clicked();
	void on_btnCancel_clicked();
	void on_btnPredict_clicked();
	void on_btnSet_clicked();

};


#endif