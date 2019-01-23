#include "Data.h"


Data::Data() {

}


//Data::Data(string n_args, ...)
//{
//	va_list ap;
//	va_start(ap, n_args);
//	string max = va_arg(ap, string);
//	for (int i = 2; i <= n_args; i++) {
//		int a = va_arg(ap, int);
//		if (a > max) max = a;
//	}
//	va_end(ap);
//	return max;
//}

//Data::Data(vector<string> file_paths) : file_paths(file_paths){
//	for (auto i : file_paths) {
//		fetchData(i);
//	}
//}

//Data::Data(string file_path){
//	int counter = 0;
//	vector<vector<double>> matrix;
//	string line;
//	ifstream myfile (file_path);
//	if (myfile.is_open())
//	{
//		while (getline(myfile, line))
//		{
//			vector<string> values = Helper::split(line, ','); //extract values
//
//			if (counter != 0) { //store data
//				vector<double> dbl_val = Helper::str2dbl(values); //converts from str to dbl
//				matrix.push_back(dbl_val);
//			}
//			else {
//				this->param_num = values.size();
//				this->param_names = values; //store column names
//			}
//
//			counter++;
//		}
//		myfile.close();
//	}
//	else 
//		printf("The file is missing!\n");
//	this->obs_num = counter-1;
//	this->data = Matrix(matrix).transpose();
//	cout<<"here1\n";
//}

//Matrix Data::fetchData(string file_path) {
//	int counter = 0;
//	vector<vector<double>> matrix;
//	string line;
//	ifstream myfile(file_path);
//	if (myfile.is_open())
//	{
//		while (getline(myfile, line))
//		{
//			vector<string> values = Helper::split(line, ','); //extract values
//
//			if (counter != 0) { //store data
//				vector<double> dbl_val = Helper::str2dbl(values); //converts from str to dbl
//				matrix.push_back(dbl_val);
//			}
//			else { //store headers
//				this->param_num = values.size();
//				this->param_names = values; //store column names
//			}
//
//			counter++;
//		}
//		myfile.close();
//	}
//	else
//		throw invalid_argument("The file is missing!\n");
//	this->obs_num = counter - 1;
//	this->data = Matrix(matrix).transpose();
//}

Matrix Data::getRow(string col_name){
	int idx = Helper::find(param_names,col_name);
	return Matrix(this->data.getMat()[idx]);
}

Matrix Data::getAllRowsExcept(string col_name){
	int idx = Helper::find(this->param_names, col_name);
	Matrix x(this->data);
	return x.remove_row(idx+1);
}

int Data::getObsNum() const{
	return obs_num;
}

int Data::getParamNum() const{
	return param_num;
}

vector<string> Data::getFilePaths() const{
	return this->file_paths;
}

Matrix Data::getData() const{
	return data;
}

vector<string> Data::getParamNames() const{
	return param_names;
}

void Data::print(){
	cout << "-- Data --" << endl;
	cout << "# of obs: " << obs_num << endl;
	cout << "# of parameters: " << param_num << endl;
	cout << "parameters names: "; 
	for(vector<string>::iterator i = param_names.begin(); i != param_names.end(); i++)
		cout << *i << " ";
	cout << endl;
	
}

Data& Data::operator= (const Data& data)
{
	this->param_names = data.getParamNames();
	this->data = data.getData();
	this->obs_num = data.getObsNum();
	this->param_num = data.getParamNum();

	return *this;
};

//Data Data::mergeByCol(Data& data) {
//	Matrix mat (this->data);
//	vector<string> names = this->param_names;
//	for (int i = 0; i < data.getParamNum(); i++) {
//		Matrix currentCol = Matrix(data.getData().getMat()[i]).transpose(); //fetch the current column and convert to matrix column
//		int colIdx = Helper::find(this->param_names, data.getParamNames()[i]); //get common column index
//		if (colIdx == -1) { //data col doesn't exist in this data
//			mat.append(currentCol, 'r'); //append the column to the right
//		}
//		else { //data col exists in this data
//
//		}
//	}
//}