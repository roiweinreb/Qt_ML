#include "ML.h"


ML::ML(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);
	setWindowTitle("Linear Regression Machine");
	ui.wChoose->hide();
	ui.tblData->setDisabled(true);
	ui.wColFilter->hide();



	/*QGridLayout *grid = new QGridLayout;
	grid->addWidget(createFirstExclusiveGroup(), 0, 0);
	grid->addWidget(createSecondExclusiveGroup(), 1, 0);
	grid->addWidget(createNonExclusiveGroup(), 0, 1);
	grid->addWidget(createPushButtonGroup(), 1, 1);
	setLayout(grid);

	setWindowTitle(tr("Group Boxes"));
	resize(480, 320);*/
}

void ML::fetchTablesData(QStringList filePaths) {
	this->tables.clear(); //clear old table
	vector<vector<string>> all_headers;

	for each (QString path in filePaths){ //get all tables
		Table table = fetchTableData(path);
		this->tables.push_back(table); //put tables in array
		all_headers.push_back(table.getColNames()); //collect all headers (with duplicates)
	}

	if (this->tables.size() > 1) { //multiple tables
		vector<string> common_headers = Helper::str_common(all_headers); //find all common headers

		if (common_headers.size() == 0) {//no common headers
			QMessageBox::warning(this, tr("Warning"), tr("There are no common parameters!!\nTables will be concatenated."));
			ui.wChoose->hide();
			this->table = concatTables(this->tables);
			this->displayedTable = this->table;
			enableTable();
		}
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
	enableColFilter(); //show the column filter feature

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

void ML::resizeEvent(QResizeEvent *event)
{
	if (this)
	{
		ui.tblData->resize(this->width() - 20, this->height() - 180);
		ui.wTools->resize(this->width() - 20, ui.wTools->height());
		//if (ui.wChoose->y() <= 160 && event->oldSize().width() > event->size().width()) { //make window smaller
		//	return;
		//}
		//else {
		//	ui.wChoose->move(QPoint(this->width() - 120, ui.wChoose->y()));
		//	ui.cbxFilter->move(QPoint(this->width() - 120, ui.cbxFilter->y()));
		//}
	}
}

Table ML::fetchTableData(QString filePath) {
	return Table::fetch_table(filePath.toStdString()); 
}

void ML::enableColFilter() { //DISPLAY COLUMN FILTER WIDGET
	//int col_num = this->table.getDimC(); //get number of columns
	//vector<string> col_names = this->table.getColNames(); //get names of columns
	//int rowIdx = -1;
	//for (int i = 0; i < col_num; i++) {
	//	QString name = col_names[i].c_str();
	//	QCheckBox *cb = new QCheckBox;
	//	//QMessageBox::warning(this, tr("Warning"), tr("%1").arg(col_names[i].c_str()));
	//	if (i % 3 == 0) {
	//		rowIdx++;
	//		QHBoxLayout *hbox = new QHBoxLayout;
	//	}
	//	cb->setText(name);
	//	cb->setFixedWidth(23 + (name.size() * 6.5));
	//	ui.lyoutCbx->addWidget(cb, rowIdx, (i % 3));
	//	//i++;
	//}
	//ui.wColFilter->show();
}
Table ML::concatTables(vector<Table>& tables) {
	Table result(tables[0]);
	for (int i = 1; i < tables.size(); i++) {
		for (int j = 0; j < tables[i].getDimC(); j++)
			result.append_col(tables[i].getColumn(j), tables[i].getColNames()[j]);
	}
	return result;
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

QStringList ML::getTableHeaders() { //GET TABLE HEADERS
	QStringList headers;
	for (int i = 0; i < ui.tblData->columnCount(); i++) {
		headers.append(ui.tblData->horizontalHeaderItem(i)->text());
	}
	return headers;
}

void ML::setResponseOptions(MLTrain& mltrain) { //PASS PARAMETERS TO MLTRAIN CLASS
	QString str;
	for (int i = 0; i < ui.tblData->columnCount(); i++) {
		str = QString::fromUtf8(this->table.getColNames()[i].c_str());
		mltrain.getUi().cbResponse->addItem(str);
	}
}

void ML::disableTable() { //HIDE TABLE
	ui.tblData->hide();
	ui.cbxFilter->setDisabled(true);
	ui.btnTrain->setDisabled(true);
}

void ML::enableTable() { //DISPLAY TABLE
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

//GETTERS

Ui::MLClass ML::getUi() { 
	return this->ui;
}

//SIGNALS

void ML::on_btnData_clicked() { //IMPORT DATA BUTTON
	auto fileNames = QFileDialog::getOpenFileNames(this, "Select CSV file", QDir::rootPath(), "CSV File (*.csv)");
	if (fileNames.isEmpty()) {
		return;
	}
	fetchTablesData(fileNames);
}

void ML::on_cbCommon_currentTextChanged(QString str) {   //CHOOSE COMMON COLUMN BUTTON
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
}

void ML::on_cbxFilter_stateChanged(int state) { //FILTER NULL CHECKBOX
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
void ML::on_btnTrain_clicked() { //TRAIN BUTTON
	MLTrain mltrain(this);
	setResponseOptions(mltrain);
	mltrain.setTable(this->displayedTable);
	mltrain.exec();
}
