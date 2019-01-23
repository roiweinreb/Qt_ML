#include "Helper.h"

using namespace std;

void Helper::print_vec(const vector<double>& vec){
	unsigned int length = vec.size();
	for(unsigned int i = 0; i < length; i++){
		cout << vec[i] << " " ;
	}
	cout << endl;
}

void Helper::print_vec(const vector<string>& vec) {
	unsigned int length = vec.size();
	for (unsigned int i = 0; i < length; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}


vector<string> Helper::split(string str, char delim){
	int idx;
	int delim_num = count(str.begin(), str.end(), delim);
	vector<string> values;
	for(int i = 0; i < delim_num; i++){
		idx = str.find(delim); //finds first comma index
		values.push_back(str.substr(0, idx));
		str = str.substr(idx + 1);
	}
	values.push_back(str); 

	return values;
}

vector<double> Helper::str2dbl(const vector<string>& str_vec){
	vector<double> dbl_vec(str_vec.size());
	transform(str_vec.begin(), str_vec.end(), dbl_vec.begin(), [](const string& val)
	{
		try{
			return stod(val);
		}
		catch(const invalid_argument& e){
			cout << "Couldn't convert string to double" << endl; 
			return (double) NAN;
		}
	});

	return dbl_vec;
}

vector<vector<double>> Helper::str2dbl(const vector<vector<string>>& str_vec){
	vector<vector<double>> dbl_vec;
	for (auto row : str_vec) {
		dbl_vec.push_back(Helper::str2dbl(row));
	}

	return dbl_vec;
}

vector<vector<string>> Helper::dbl2str(const vector<vector<double>>& dbl_vec){
	vector<vector<string>> str_vec;
	for (auto row : dbl_vec) {
		str_vec.push_back(Helper::dbl2str(row));
	}

	return str_vec;
}

vector<string> Helper::dbl2str(const vector<double>& dbl_vec) {
	vector<string> str_vec(dbl_vec.size());
	transform(dbl_vec.begin(), dbl_vec.end(), str_vec.begin(), [](const double& val)
	{
		try {
			return std::to_string(val);
		}
		catch (const invalid_argument& e) {
			cout << "Couldn't convert double to string" << endl;
			string s = " ";
			return s;
		}
	});

	return str_vec;
}

vector<string> Helper::unique(vector<string> vec1, vector<string> vec2) {
	vector<string> result;
	vec1.insert(vec1.end(), vec2.begin(), vec2.end()); //append vec2 to vec1
	for (int i = 0; i < vec1.size(); i++){
		if (Helper::find(result, vec1[i]) == -1)
			result.push_back(vec1[i]);
	}
	
	return result;
}

vector<string> Helper::unique(vector<string> vec) {
	vector<string> result;
	for (auto str : vec)
		if (!Helper::str_contains(result, str))
			result.push_back(str);
	return result;
}

int Helper::find(const vector<string>& vec, string str){
	int length = vec.size();
	for(int i = 0; i < length; i++){
		if(vec[i] == str)
			return i;
	}
	return -1;
}

vector<int> Helper::find_all(const vector<string>& vec, string str) {
	vector<int> result;
	int length = vec.size();
	for (int i = 0; i < length; i++) {
		if (vec[i] == str)
			result.push_back(i);
	}

	return result;
}

int Helper::find(const vector<double>& vec, double dbl) {
	int length = vec.size();
	for (int i = 0; i < length; i++) {
		if (vec[i] == dbl)
			return i;
	}
	return -1;
}

double Helper::vec_std(const vector<double>& vec, const double mean){
	double var = 0;
	for( int n = 0; n < vec.size(); n++){
		var += (vec[n] - mean) * (vec[n] - mean);
	}
	var /= vec.size();
	if(var == 0)
		return 0.000000001;
	return sqrt(var);
}


bool Helper::dbl_contains(vector<double> dbl_vec, double dbl) {
	if (Helper::find(dbl_vec, dbl) == -1) {
		return false;
	}
	return true;
}

bool Helper::str_contains(vector<string> str_vec, string str) {
	if (Helper::find(str_vec, str) == -1) {
		return false;
	}
	return true;
}

vector<string> Helper::str_common(vector<string> vec1, vector<string> vec2) {
	vector<string> result;
	for (auto str : vec1)
		if (Helper::str_contains(vec2, str)) {
			result.push_back(str);
			vec2.erase(vec2.begin() + Helper::find(vec2, str));
		}
	return result;
}

vector<string> Helper::str_common(vector<vector<string>> str_arr) {
	vector<string> all;
	for (auto vec : str_arr)
		all.insert(all.end(), vec.begin(), vec.end());
	all = Helper::unique(all); //get only unique values
	for (auto vec : str_arr) {
		all = Helper::str_common(all, vec);
	}
	return all;
}
