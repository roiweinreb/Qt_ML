#include "Table.h"

//CONSTRUCTORS

Table::Table()
{
	this->values = vector<vector<string>>{ {""} };
	this->col_names = vector<string>{ "" };
}

Table::Table(vector<vector<string>> values, vector<string> col_names) {
	if (values.size() == 0 || col_names.size() == 0) { //check if table is empty
		throw invalid_argument("matrix is empty");
	}

	this->dimR = values.size();
	this->dimC = col_names.size();

	for (int i = 0; i < this->dimR; i++) { //check each row has same amount of columns
		if (values[i].size() != this->dimC)
			throw invalid_argument("Matrix rows have different amount of columns");
	}
	this->values= values;
	this->col_names = col_names;
}

//DESTRUCTOR

Table::~Table()
{
}

//METHODS

Table Table::fetch_table(string filepath) {
	vector<vector<string>> table;
	vector<string> names;
	int counter = 0;
	string line;
	ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			vector<string> values = Helper::split(line, ','); //extract values
			
			if(counter == 0) //store headers
				names = values;
			else  //store data
				table.push_back(values);

			counter++;
		}
		myfile.close();
	}
	else
		throw invalid_argument("The file is missing!\n");
	return Table(table, names);
}

vector<Table> Table::fetch_tables(vector<string> paths) {
	vector<Table> tables;
	for (auto path : paths) {
		tables.push_back(Table::fetch_table(path));
	}
	return tables;
}

Table& Table::append_row(vector<string> new_data) {
	if (new_data.size() != this->dimC) { //check dimensions
		throw invalid_argument("dimensions aren't valid");
	}

	this->values.push_back(new_data);
	this->dimR++;
	return *this;
}

Table& Table::append_col(vector<string> new_data, string col_name, int start ) {
	int index = Helper::find(this->col_names, col_name);
	
	if (index != -1 || start > this->values.size()-1) {
		throw invalid_argument("this column already exists or start index is out of bounds");
	}

	this->col_names.push_back(col_name); //add new column name
	int endIdx = start + new_data.size() - 1; //calculate the end index of the new data


	for (int i = 0; i < max((int)this->values.size(), endIdx + 1); i++) {
		if (i < start || i > endIdx)
			this->values[i].push_back(" "); //padding the new column with ""
		else if (i > this->values.size() - 1) { //exceeded original data indeces
			vector<string> vec(this->col_names.size(), " ");
			vec[this->col_names.size() - 1] = new_data[i - start];
			this->values.push_back(vec);
		}
		else
			this->values[i].push_back(new_data[i - start]);
	}

	this->dimC++;
	return *this;
}

Table Table::filter_by_param_value(string param_name, string value) {
	vector<string> headers = this->getColNames();
	vector<vector<string>> values;
	int colIdx = Helper::find(headers, param_name);
	if (colIdx == -1) {
		throw invalid_argument("parameter doesn't exist in the table");
	}
	for (auto row : this->getValues()) {
		if (row[colIdx] == value)
			values.push_back(row);
	}
	return Table(values, headers);

}

Table Table::merge_tables(Table table1, Table table2) {
	Table result = table1;
	vector<int> indeces;
	for (int i = 0; i < table2.getColNames().size(); i++) {
		string header = table2.getColNames()[i];
		if (Helper::find(table1.getColNames(), header) == -1)
			result.append_col(vector<string>(table1.getDimR(), " "), header);
			indeces.push_back(i);
	}

	for (auto row : table2.getValues()){
		result.append_row(row, table2.getColNames());
	}

	return result;
}

Table Table::merge_tables_by_col(Table table1, Table table2, string colName) {
	if (!Helper::str_contains(table1.getColNames(), colName) || !Helper::str_contains(table2.getColNames(), colName))
		throw invalid_argument("Parameter doesn't appear in both tables");

	vector<vector<string>> result;
	vector<string> headers = Helper::unique(table1.getColNames(), table2.getColNames()); //create headers vector
	int colIdx1 = Helper::find(table1.getColNames(), colName); //get column idx in table1
	int colIdx2 = Helper::find(table2.getColNames(), colName); //get column idx in table2
	vector<string> unique_vals = Helper::unique(table1.getColumn(colIdx1), table2.getColumn(colIdx2)); //get unique values of requested column


	for (auto str : unique_vals) {
		vector<int> rowIdx1 = Helper::find_all(table1.getColumn(colIdx1), str);
		vector<int> rowIdx2 = Helper::find_all(table2.getColumn(colIdx2), str);
		if (rowIdx1.size() == 0) { //value doesn't appear in table1
			vector<string> row1(table1.getDimC() - 1, " "); //create empty vector
			row1.insert(row1.begin() + colIdx1, str);
			for (auto idx2 : rowIdx2) {
				vector<string> row2 = table2.getValues()[idx2]; //get data from table2
				row2.erase(row2.begin() + colIdx2); //remove redundant value
				row1.insert(row1.end(), row2.begin(), row2.end());
				result.push_back(row1);
			}
		}
		else if (rowIdx2.size() == 0) { //value doesn't appear in table2
			for (auto idx1 : rowIdx1) {
				vector<string> row2(table2.getDimC() - 1, " ");
				vector<string> row1 = table1.getValues()[idx1];
				row1.insert(row1.end(), row2.begin(), row2.end());
				result.push_back(row1);
			}
		}
		else {
			for (auto idx1 : rowIdx1) { //value appear in both tables
				for (auto idx2 : rowIdx2) {
					vector<string> row1 = table1.getValues()[idx1];
					vector<string> row2 = table2.getValues()[idx2];
					row2.erase(row2.begin() + colIdx2);
					row1.insert(row1.end(), row2.begin(), row2.end());
					result.push_back(row1);
				}
			}
		}
	}

	return Table(result, headers);
}

Table Table::inner_join(Table table1, Table table2, string colName) {
	if (!Helper::str_contains(table1.getColNames(), colName) || !Helper::str_contains(table2.getColNames(), colName))
		throw invalid_argument("Parameter doesn't appear in both tables");

	vector<vector<string>> result;
	vector<string> headers = Helper::unique(table1.getColNames(), table2.getColNames()); //create headers vector
	int colIdx1 = Helper::find(table1.getColNames(), colName); //get column idx in table1
	int colIdx2 = Helper::find(table2.getColNames(), colName); //get column idx in table2
	vector<string> unique_vals = Helper::unique(table1.getColumn(colIdx1), table2.getColumn(colIdx2)); //get unique values of requested column


	for (auto str : unique_vals) {
		vector<int> rowIdx1 = Helper::find_all(table1.getColumn(colIdx1), str);
		vector<int> rowIdx2 = Helper::find_all(table2.getColumn(colIdx2), str);
		for (auto idx1 : rowIdx1) {
			vector<string> row1 = table1.getValues()[idx1];
			for (auto idx2 : rowIdx2) {
				vector<string> row2 = table2.getValues()[idx2];
				row2.erase(row2.begin() + colIdx2);
				row1.insert(row1.end(), row2.begin(), row2.end());
				result.push_back(row1);
			}
		}
	}

	return Table(result, headers);
}

bool Table::hasNull() {
	for (auto row : this->values)
		if (Helper::str_contains(row, " "))
			return true;
	return false;
}

void Table::append_row(vector<string> new_data, vector<string> data_headers) {
	vector<int> indeces;
	for (auto header : data_headers){
		int idx = Helper::find(this->col_names, header);
		indeces.push_back(idx);
	}

	vector<string> new_row(this->dimC, " ");
	for (int i = 0; i < new_data.size(); i++){
		new_row[indeces[i]] = new_data[i];
	}

	this->append_row(new_row);

}

void Table::print_table() {
	Helper::print_vec(this->col_names);
	cout << this->dimR << " X " << this->dimC << endl;
	for (auto vec : this->values) {
		Helper::print_vec(vec);
	}
}

Table Table::filter_null() {
	vector<vector<string>> result;
	for (auto vec : this->values) {
		if (Helper::find(vec, " ") == -1) { //no null value 
			result.push_back(vec);
		}
	}
	return Table(result, this->col_names);
}

Table Table::remove_column(string colName) {
	int index = Helper::find(this->col_names, colName);
	if (index == -1)
		throw invalid_argument("Parameter doesn't exist");
	vector<string> headers = this->col_names;
	headers.erase(headers.begin() + index); //remove specified column name

	vector<vector<string>> values = this->values;
	int i = 0;
	for (auto row : values) {
		row.erase(row.begin() + index);
		values[i] = row;
		i++;
	}
	return Table(values, headers);
}

vector<string> Table::getColumn(int index) {
	if (index > this->dimC || index < 0)
		throw invalid_argument("Index isn't valid");

	vector<string> column;
	for (auto row : this->values)
		column.push_back(row[index]);
	return column;
}

vector<string> Table::getColumn(string colName) {
	int index = Helper::find(this->col_names, colName);
	if (index == -1)
		throw invalid_argument("Parameter doesn't exist");
	vector<string> column;
	for (auto row : this->values)
		column.push_back(row[index]);
	return column;
}

//GETTERS

int Table::getDimR() const{
	return this->dimR;
}

int Table::getDimC() const{
	return this->dimC;
}

vector<vector<string>> Table::getValues() const{
	return this->values;
}

vector<string> Table::getColNames() const {
	return this->col_names;
}


//OPERATORS

Table& Table::operator= (Table& table)
{
	this->dimR = table.getDimR();
	this->dimC = table.getDimC();
	this->values = table.getValues();
	this->col_names = table.getColNames();

	return *this;
}
