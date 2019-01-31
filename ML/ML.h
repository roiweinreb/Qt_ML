#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ML.h"
#include "MLTrain.h"
#include <iostream>
#include <qstandarditemmodel.h>
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qfile.h>
#include "Table.h"
//#include <Data.h>

using namespace std;

class ML : public QMainWindow
{
	Q_OBJECT;

public:
	explicit ML(QWidget *parent = Q_NULLPTR);
	Ui::MLClass getUi();
	Table fetchTableData(QString filePath);
	void fetchTablesData(QStringList filePaths);
	//Data getData();
	//void execMLTrain();
	void updateTableHeaders(QStringList new_headers);
	void updateTableData(QStringList new_data, QStringList data_headers);
	QStringList getTableHeaders();
	void setResponseOptions(MLTrain& mltrain);
	QStringList stdToQStringList(vector<string> vec);
	void displayOnTableWidget(Table tab);
	void disableTable();
	void enableTable();
	void enableColFilter();
	Table concatTables(vector<Table>& tables);
	void resizeEvent(QResizeEvent* event);

private:
	Ui::MLClass ui;
	Ui::Dialog ui_MLTrain;
	//Data data;
	Table table;
	Table displayedTable;
	vector<Table> tables;
	


private slots:
	void on_btnData_clicked();
	void on_btnTrain_clicked();
	void on_cbCommon_currentTextChanged(QString str);
	void on_cbxFilter_stateChanged(int state);

};
