#include "ML.h"


ML::ML(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);
	setWindowTitle("Linear Regression Machine");
	ui.wChoose->hide();
	ui.tblData->setDisabled(true);
}

void ML::fetchTablesData(QStringList filePaths) {
	this->tables.clear(); //clear old table
	vector<vector<string>> all_headers;

	for each (QString path in filePaths){ //get all tables
		Table table = fetchTableData(path);
		this->tables.push_back(table); //put tables in array
		all_headers.push_back(table.getColNames()); //collect all headers (with duplicates)
	}

	if (this->tables.size() > 1) {
		vector<string> common_headers = Helper::str_common(all_headers); //find all common headers

		if (common_headers.size() == 0) //if there is no common headers
			QMessageBox::warning(this, tr("Warning"), tr("There are no common parameters!!"));
		else {						//if there are common headers
			ui.cbCommon->blockSignals(true);
			ui.cbCommon->clear();
			ui.cbCommon->addItem("--Not Selected--");
			for (string str : common_headers) //add common headers to combo box
				ui.cbCommon->addItem(str.c_str());
			ui.cbCommon->blockSignals(false);
			ui.wChoose->show();
		}
	}
	else {
		this->table = this->tables[0];
		this->displayedTable = this->table;
		enableTable();
	}

}

void ML::displayOnTableWidget(Table tab) {
	ui.tblData->setColumnCount(tab.getDimC());
	ui.tblData->setRowCount(tab.getDimR());
	ui.tblData->setHorizontalHeaderLabels(stdToQStringList(tab.getColNames()));
	for (int j = 0; j < tab.getDimR(); j++) {
		for (int i = 0; i < tab.getDimC(); i++) {
			ui.tblData->setItem(j, i, new QTableWidgetItem(tab.getValues()[j][i].c_str()));
		}
	}
}

Table ML::fetchTableData(QString filePath) {
	return Table::fetch_table(filePath.toStdString()); 
}

QStringList ML::stdToQStringList(vector<string> vec) {
	QStringList result;
	for (auto str : vec) {
		result.append(QString(str.c_str()));
	}
	return result;
}

void ML::updateTableHeaders(QStringList new_headers) {
	QStringList headers = getTableHeaders();
	for (QStringList::iterator i = new_headers.begin(); i != new_headers.end(); i++) {
		if (!headers.contains(*i)) {
			headers.append(*i);
		}
	}
	ui.tblData->setHorizontalHeaderLabels(headers);
}

QStringList ML::getTableHeaders() {
	QStringList headers;
	for (int i = 0; i < ui.tblData->columnCount(); i++) {
		headers.append(ui.tblData->horizontalHeaderItem(i)->text());
	}
	return headers;
}

void ML::setResponseOptions(MLTrain& mltrain) {
	QString str;
	for (int i = 0; i < ui.tblData->columnCount(); i++) {
		str = QString::fromUtf8(this->table.getColNames()[i].c_str());
		mltrain.getUi().cbResponse->addItem(str);
	}
}

void ML::disableTable() {
	ui.tblData->hide();
	ui.cbxFilter->setDisabled(true);
	ui.btnTrain->setDisabled(true);
}

void ML::enableTable() {
	ui.tblData->setEnabled(true);
	displayOnTableWidget(this->displayedTable);
	ui.tblData->show();
	if (this->table.hasNull()) { // if the original table has nulls
		ui.cbxFilter->setEnabled(true);
	}
	else {
		ui.cbxFilter->setDisabled(true);
		ui.btnTrain->setEnabled(true);
	}
}

Ui::MLClass ML::getUi() {
	return this->ui;
}

//SIGNALS

void ML::on_btnData_clicked() {
	auto fileNames = QFileDialog::getOpenFileNames(this, "Select CSV file", QDir::rootPath(), "CSV File (*.csv)");
	if (fileNames.isEmpty()) {
		return;
	}
	fetchTablesData(fileNames);
}

void ML::on_cbCommon_currentTextChanged(QString str) {
	if (str == "--Not Selected--") {
		disableTable();
		return;
	}

	//if some header was chosen
	Table result = this->tables[0]; //initialize result table
	for (int i = 1; i < this->tables.size(); i++)
		result = Table::merge_tables_by_col(result, this->tables[i], str.toStdString());
	this->table = result;
	this->displayedTable = this->table;
	enableTable();

	//if (!this->table.hasNull()) //if original table has nulls
	//	ui.cbxFilter->setDisabled(true);
	//else //if it doesn't
	//	ui.cbxFilter->setEnabled(true);
	

	//if (!this->table.hasNull()) { //if the table doesn't have null values
	//	ui.btnTrain->setEnabled(true);
	//	ui.cbxFilter->setDisabled(true);
	//}
	//else { //if the table doesn't have null values
	//	ui.btnTrain->setDisabled(true);
	//	ui.cbxFilter->setEnabled(true);
	//}
}

void ML::on_cbxFilter_stateChanged(int state) {
	if (state) { //checked
		this->displayedTable = this->table.filter_null();
		enableTable();
		ui.btnTrain->setEnabled(true);
	}
	else { //not checked
		this->displayedTable = this->table;
		enableTable();
		ui.btnTrain->setDisabled(true);
	}
}
void ML::on_btnTrain_clicked() {
	MLTrain mltrain(this);
	setResponseOptions(mltrain);
	mltrain.setTable(this->table);
	mltrain.exec();
}
