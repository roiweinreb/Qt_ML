#include "LR2.h"


LR2::LR2() {

}

LR2::LR2(Table tab, string response) {
	cout << ">>> LR2 constructor\n";
	this->response_str = response;
	this->response = Matrix(Helper::str2dbl(tab.getColumn(response))); //extract response data 
	this->data_trans = Matrix(Helper::str2dbl(tab.remove_column(response).getValues()));
	this->data = this->data_trans.transpose(); //apply transpose on data matrix
	this->obs_num = tab.getDimR();
	this->pred_num = tab.getDimC() - 1;
	this->data_trans.normalize(1); //normalize data
	// this->data_trans = this->data.transpose();
	cout << "LR2 constructor >>>\n";
}

void LR2::train(double alpha, int max_iter) {
	gradient_descent(alpha, max_iter);
	vector<double> t_data = this->theta.getMat()[0];
	std::cout << "Theta values:\n";
	for(vector<double>::iterator i = t_data.begin(); i != t_data.end(); i++)
		std::cout << *i << " ";
	std::cout << endl;
}

void LR2::gradient_descent(const double alpha, const int max_iter) {
	double MAX_COST = 100000;
	double MIN_COST = 1.0e-5;
	int obs = this->obs_num;
	int preds = this->pred_num;
	this->theta = Matrix (vector<double>(preds+1, 0.0)); //initialize all theta to 0
	for(int iter = 0; iter < max_iter; iter++){
		cout << "iter: " << iter << "\n";
		Matrix predictions = calculate_predictions(); //compute predictions
		Matrix error = predictions.transpose() - this->response; //compute error
		costValues.push_back(compute_cost(error)); //compute cost
		if(costValues.size() >=2 && costValues.back() - costValues.end()[-2] > 0) //check cost value convergence
			throw invalid_argument("The cost function isn't converging! Try a smaller alpha..");
		if(costValues.size() >=2 && costValues.end()[-2] - costValues.back() <= MIN_COST) //check cost convergence condition
			break;

				
		//tuning theta - GD
		Matrix x0(vector<double>(this->obs_num,1)); //initialize a vector with all ones
		Matrix x(this->data_trans.append(x0.transpose(),'l')); //append x0 to the left of predictors data
		this->theta = this->theta - (error * x).scale(alpha / obs);
	}
	cout<< "gradient_descent >>>\n";
}

Matrix LR2::calculate_predictions() {
	return h();
}

Matrix LR2::h() {
	Matrix x0(vector<double>(this->obs_num,1)); //initialize a vector with all ones
	Matrix x(this->data_trans);
	x = x.append(x0.transpose(), 'l'); //append x0 column to the left
	this->predictions =  x*this->theta.transpose();
	return this->predictions;
}

double LR2::h(vector<double>& x) {
	for(int i = 0; i < x.size(); i++)
		x[i] = (x[i] - this->data_trans.getMeanC()[i]) / this->data_trans.getRangeC()[i];
	x.insert(x.begin(),1); //add x0 value - 1
	if(this->theta.getDimC() != x.size())//check dimensions validity
		throw invalid_argument("Dimensions aren't valid");

	Matrix prediction(x*this->theta.transpose());
	return prediction.getMat()[0][0];
}

double LR2::predict(vector<double>& x) {
	return h(x);
}

double LR2::compute_cost(const Matrix& error) {
	return 1.0 / (2.0 * this->obs_num) * (error * error.transpose()).getMat()[0][0];
}

void LR2::normalize(){
	vector<vector<double>> mat = this->data.getMat();
	vector<double> mean;
	vector<double> range;
	double sum = 0;
	for(int i = 0; i < this->pred_num; i++){
		mean.push_back(accumulate(mat[i].begin(),mat[i].end(),0.0) / this->obs_num); //calculate the mean of each feature
		range.push_back(*max_element(mat[i].begin(),mat[i].end()) - *min_element(mat[i].begin(),mat[i].end()));
		for(int j = 0; j < this->obs_num; j++)
			mat[i][j] = (mat[i][j] - mean[i]) / range[i]; 
	}
	this->mean = Matrix(mean);
	this->sd = Matrix(sd);
	this->n_data = Matrix(mat);
	cout<<"after normalization:\n";
	this->n_data.print_mat();
}

LR2& LR2::operator= (const LR2& lr)
{
	this->response_str = lr.response_str;
	this->response = lr.response;
	this->data = lr.data;
	this->obs_num = lr.obs_num;
	this->pred_num = lr.pred_num;
	this->data_trans = lr.data_trans; //apply transpose on data matrix
	this->costValues = lr.costValues;
	this->theta = lr.theta;
	this->mean = lr.mean;
	this->sd = lr.sd;
	this->predictions = lr.predictions;

	return *this;
};

vector<string> LR2::getPreds(vector<string> params) {
	int idx = Helper::find(params, this->response_str);
	params.erase(params.begin() + idx);
	return params;
}

double LR2::get_r_squared() {
	double actual_mean = this->response.sum() / this->obs_num;
	Matrix mean(vector<double>(this->obs_num, actual_mean));
	Matrix actual_mean_diff_squared = (this->response - mean).ew_power(2);
	Matrix predict_mean_diff_squared = (this->predictions.transpose() - mean).ew_power(2);
	return predict_mean_diff_squared.sum() / actual_mean_diff_squared.sum();
}




