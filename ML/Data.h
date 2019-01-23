#pragma once
#include "Helper.h"
#include "Matrix.h"
#include <fstream>
#include<stdarg.h>


using namespace std;

class Data{
	private:
		vector<string> param_names;
		Matrix data; //data[i] each feature's data
		int obs_num;
		int param_num;
		vector<string> file_paths;
	
	public:
		Data();
		Data(vector<string> file_paths);
		Data(string n_args, ...);
		Data(string file_path);
		Data(Matrix mat, vector<string> param_names);
		int getObsNum() const;
		int getParamNum() const;
		vector<string> getFilePaths() const;
		Matrix getData() const;
		vector<string> getParamNames() const;
		Matrix getRow(string col_name);
		Matrix getAllRowsExcept(string col_name);
		void print();
		//Data mergeByCol(Data& data);
		Data& operator=(const Data& data);
};