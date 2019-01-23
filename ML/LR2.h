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


	// First feature
	vector<double> x;

	// Target feature
	vector<double> y;

	LR2();
	// The theta coefficients


	LR2(Table tab, string response);

	/**
	 * Create a new instance from the given data set.
	 */
	//LR2(Data data, string response);

	/**
	 * Train the model with the supplied parameters.
	 *
	 * @param alpha         The learning rate, e.g. 0.01.
	 * @param iterations    The number of gradient descent steps to do.
	 */
	void train(double alpha, int max_iter = 3000);

	vector<string> getPreds(vector<string> params);
	/**
	 * Try to predict y, given an x.
	 */
	double predict(vector<double>& x);

	/**
	 * Compute the cost J.
	 */
	double compute_cost(const Matrix& error);

	/**
	 * Compute the hypothesis. for train process
	 */
	Matrix h();

	/**
	 * Compute the prediction. for predict process (after model is ready)
	 */
	double h(vector<double>& x);

	/**
	 * Calculate the target feature from the other ones.
	 */
	Matrix calculate_predictions();

	/**
	 * Performs gradient descent to learn theta by taking num_items gradient steps with learning rate alpha.
	 */
	void gradient_descent(const double alpha, const int max_iter);

	void normalize();

	LR2& operator=(const LR2& lr);

	

};


#endif //ML_LR2_H
