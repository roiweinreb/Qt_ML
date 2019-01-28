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
	static void print_vec(const std::vector<double>& vec);
	static void print_vec(const std::vector<string>& vec);
	static std::vector<string> split(string str, char delim);
	static std::vector<string> unique(std::vector<string> vec1, std::vector<string> vec2);
	static std::vector<string> unique(std::vector<string> vec);
	static std::vector<double> str2dbl(const std::vector<string>& str_vec);
	static std::vector<string> dbl2str(const std::vector<double>& dbl_vec);
	std::vector<std::vector<string>> dbl2str(const std::vector<std::vector<double>>& dbl_vec);
	static std::vector<std::vector<double>> str2dbl(const std::vector<std::vector<string>>& str_vec);
	static bool str_contains(std::vector<string> str_vec, string str);
	static bool dbl_contains(std::vector<double> dbl_vec, double dbl);
	static int find(const std::vector<string>& vec, string str);
	static std::vector<int> find_all(const std::vector<string>& vec, string str);
	static int find(const std::vector<double>& vec, double dbl);
	static std::vector<string> str_common(std::vector<string> vec1, std::vector<string> vec2);
	static std::vector<string> str_common(std::vector<std::vector<string>> str_arr);
	static double vec_std(const std::vector<double>& vec, const double mean);
};