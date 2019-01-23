#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

class Helper {

public:
	// static vector<vector<double>> *duplicate_mat(const vector<vector<double>>& mat1, const vector<vector<double>>& mat2);
	// static void print_mat(const vector<vector<double>>& mat);
	static void print_vec(const vector<double>& vec);
	static void print_vec(const vector<string>& vec);
	static vector<string> split(string str, char delim);
	static vector<string> unique(vector<string> vec1, vector<string> vec2);
	static vector<string> unique(vector<string> vec);
	static vector<double> str2dbl(const vector<string>& str_vec);
	static vector<string> dbl2str(const vector<double>& dbl_vec);
	vector<vector<string>> dbl2str(const vector<vector<double>>& dbl_vec);
	static vector<vector<double>> str2dbl(const vector<vector<string>>& str_vec);
	static bool str_contains(vector<string> str_vec, string str);
	static bool dbl_contains(vector<double> dbl_vec, double dbl);
	static int find(const vector<string>& vec, string str);
	static vector<int> find_all(const vector<string>& vec, string str);
	static int find(const vector<double>& vec, double dbl);
	static vector<string> str_common(vector<string> vec1, vector<string> vec2);
	static vector<string> str_common(vector<vector<string>> str_arr);
	static double vec_std(const vector<double>& vec, const double mean);
};