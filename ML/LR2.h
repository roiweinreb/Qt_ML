#pragma once
//#include "Data.h"
#include "Table.h"
#include "Matrix.h"
#include <numeric>
#include <qdialog.h>
#ifndef ML_LR2_H
#define ML_LR2_H

using namespace std;

class LR2 {

public:

	Matrix data; //predictors data - data[i] contains all data of a predictor
	Matrix data_trans; //predictors data - data_trans[i] contains data point 
	Matrix response; //response data
	string response_str;
	Matrix theta;
	Matrix n_data; //normalized data
	int obs_num; // number of observations  
	int pred_num; //number of predictors
	Matrix mean;
	Matrix sd;
	vector<double> costValues;
	Matrix predictions;


	vector<double> x;

	vector<double> y;

	LR2();


	LR2(Table tab, string response);

	void train(double alpha, int max_iter = 3000);

	vector<string> getPreds(vector<string> params);

	double predict(vector<double>& x);

	double compute_cost(const Matrix& error);

	Matrix h();

	double h(vector<double>& x);

	Matrix calculate_predictions();

	void gradient_descent(const double alpha, const int max_iter);

	void normalize();

	double get_r_squared();

	LR2& operator=(const LR2& lr);

	

};


#endif //ML_LR2_H
