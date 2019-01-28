#pragma once
#include <vector>
#include <fstream>
#include <numeric>
#include "Helper.h"

using namespace std;

class Table
{
public:
	Table();
	Table(vector<vector<string>> values, vector<string> col_names);
	~Table();
	void print_table();
	Table& append_row(vector<string> new_data); //append row 
	void append_row(vector<string> new_data, vector<string> data_headers);
	Table& append_col(vector<string> new_data, string col_name, int start = 0); //append a column. data will be added from row "start"
	Table filter_null();
	Table filter_by_param_value(string param_name, string value);
	Table remove_column(string colName);
	vector<string> getColumn(int index);
	vector<string> getColumn(string colName);
	bool hasNull();
	Table& operator=(Table& table); //assign operator
	static Table merge_tables(Table table1, Table table2);
	static Table inner_join(Table table1, Table table2, string colName); //inner joins two tables by a selected common column
	static Table merge_tables_by_col(Table table1, Table table2, string colName); //merge by a specific column
	static Table fetch_table(string filepath);
	static vector<Table> fetch_tables(vector<string> paths);

	//Getters
	int getDimR() const;
	int getDimC() const;
	vector<vector<string>> getValues() const;
	vector<string> getColNames() const;

private:
	int dimR;
	int dimC;
	vector<vector<string>> values;
	vector<string> col_names;
};

