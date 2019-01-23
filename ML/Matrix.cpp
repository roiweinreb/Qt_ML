#include "Matrix.h"

using namespace std;

//each vector is considered to be a row vector
Matrix::Matrix(){ //def constructor
	this->dimR = 0;
	this->dimC = 0;
	vector<vector<double>> mat;
	this->mat = mat;
};

//each vector is considered to be a row vector
Matrix::Matrix(int dimR, int dimC){ //constructor
	this->dimR = dimR;
	this->dimC = dimC;
	this->init_mat(dimR,dimC);
};

Matrix::Matrix(const vector<vector<double>>& mat){
	this-> dimR = mat.size();
	this-> dimC = mat[0].size();
	this-> mat = mat;
	// this->normalize(0);
	// this->normalize(1);
}

Matrix::Matrix(const vector<double>& mat){
	vector<vector<double>> matrix;
	matrix.push_back(mat);
	this-> dimR = matrix.size();
	this-> dimC = matrix[0].size();
	this-> mat = matrix;
	// this->normalize(0);
	// this->normalize(1);
}

Matrix::Matrix(const Matrix& mat){
	this-> dimR = mat.getDimR();
	this-> dimC = mat.getDimC();
	this-> mat = mat.getMat();
	// this->meanR = mat.getMeanR();
	// this->rangeR = mat.getRangeR();
	// this->meanC = mat.getMeanC();
	// this->rangeC = mat.getRangeC();
}

void Matrix::init_mat(int dimR, int dimC){
	string value;
	vector<double> vec;
	cout << " -- Initializing Matrix --" << endl;
	for(int i = 0; i < dimR; i++){
		for(int j = 0; j < dimC; j++){
			cout << "Enter a value for (" << i << " , " << j << ")" << endl;
			cin >> value;
			vec.push_back(stod(value));
		}
			this->mat.push_back(vec);
			vec.clear();
	}
}

void Matrix::print_mat() const{
	cout<< "Matrix: " << this->dimR << "x" << this->dimC<< endl;
	for(int i = 0; i < this->dimR; i++){ //iterates over each row vector
		for(int j = 0; j < this->dimC; j++){ //iterate over each column in a row vector
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::transpose() const{
	vector<vector<double>> mat_trans;
	vector<double> vec;
	for(int i = 0; i < dimC; i++){ 
		for(int j = 0; j < dimR; j++){ 
			vec.push_back(mat[j][i]);
		}
		mat_trans.push_back(vec);
		vec.clear();
	}
	return Matrix(mat_trans);
}

int Matrix::getDimR() const{
	return this->dimR;
}

int Matrix::getDimC() const{
	return this->dimC;
}

vector<vector<double>> Matrix::getMat() const{
	return mat;
}

vector<double> Matrix::getMeanR() const{
	return this->meanR;
}

vector<double> Matrix::getMeanC() const{
	return this->meanC;
}

vector<double> Matrix::getRangeR() const{
	return this->rangeR;
}

vector<double> Matrix::getRangeC() const{
	return this->rangeC;
}

void Matrix::normalize(const int axis){
	if(axis == 0){ //rows normalization
		vector<double> mean(this->dimR);
		vector<double> range(this->dimR);
		vector<vector<double>> mat(this->dimR,vector<double>(this->dimC)); 
		for(int i = 0; i < mat.size(); i++){
			mean[i] = accumulate(this->mat[i].begin(),this->mat[i].end(),0.0) / this->dimC; //calculate mean
			range[i] = *max_element(this->mat[i].begin(),this->mat[i].end()) - 
				*min_element(this->mat[i].begin(),this->mat[i].end()); //calculate range
			for(int j = 0; j < mat[0].size(); j++){
				mat[i][j] = (this->mat[i][j] - mean[i]) / range[i]; //normalize elements
			}
		}
		this->meanR = mean;
		this->rangeR = range;
		this->mat = mat;
	}

	if(axis == 1){ //columns normalization
		vector<double> mean(this->dimC);
		vector<double> range(this->dimC);
		vector<vector<double>> trans = this->transpose().mat;
		for(int i = 0; i < trans.size(); i++){
			mean[i] = accumulate(trans[i].begin(),trans[i].end(),0.0) / this->dimR; //calculate mean
			range[i] = *max_element(trans[i].begin(),trans[i].end()) - 
				*min_element(trans[i].begin(),trans[i].end()); //calculate range
			for(int j = 0; j < trans[0].size(); j++){
				trans[i][j] = (trans[i][j] - mean[i]) / range[i]; //normalize elements
			}
		}
		this->meanC = mean;
		this->rangeC = range;
		this->mat = Matrix(trans).transpose().getMat();
	}
}

Matrix operator*(const Matrix& mat1, const Matrix& mat2){
	int rows1 = mat1.getDimR();
	int rows2 = mat2.getDimR();
	int columns1 = mat1.getDimC();
	int columns2 = mat2.getDimC();
	if(columns1 != rows2){ //check valid dimensions
		throw invalid_argument("Dimensions are not valid!");
	}
	vector<double> vec;
	vector<vector<double>> result_mat;
	vector<vector<double>> matrix1 = mat1.getMat();
	vector<vector<double>> matrix2 = mat2.getMat();
	double sum = 0;
	for(int i = 0; i < rows1; i++){
		for(int k = 0; k < columns2; k++){
			for(int j = 0; j < columns1; j++){
				sum += matrix1[i][j] * matrix2[j][k];
			}
			vec.push_back(sum);
			sum = 0;
		}
		result_mat.push_back(vec);
		vec.clear();
	}
	return Matrix(result_mat) ;
}

Matrix operator/(const Matrix& mat1, const Matrix& mat2){
	int rows1 = mat1.getDimR();
	int rows2 = mat2.getDimR();
	int columns1 = mat1.getDimC();
	int columns2 = mat2.getDimC();
	if(columns1 != columns2 || rows1 != rows2){ //check valid dimensions
		throw invalid_argument("Dimensions are not valid!");
	}

	vector<double> vec;
	vector<vector<double>> result_mat;
	vector<vector<double>> matrix1 = mat1.getMat();
	vector<vector<double>> matrix2 = mat2.getMat();
	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < columns1; j++){
			vec.push_back(matrix1[i][j] / matrix2[i][j]);
		}
		result_mat.push_back(vec);
		vec.clear();
	}
	return Matrix(result_mat);
}

Matrix operator-(const Matrix& mat1, const Matrix& mat2){
	int rows1 = mat1.getDimR();
	int rows2 = mat2.getDimR();
	int columns1 = mat1.getDimC();
	int columns2 = mat2.getDimC();
	if(columns1 != columns2 || rows1 != rows2){ //check valid dimensions
		throw invalid_argument("Dimensions are not valid!");
	}

	vector<double> vec;
	vector<vector<double>> result_mat;
	vector<vector<double>> matrix1 = mat1.getMat();
	vector<vector<double>> matrix2 = mat2.getMat();
	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < columns1; j++){
			vec.push_back(matrix1[i][j] - matrix2[i][j]);
		}
		result_mat.push_back(vec);
		vec.clear();
	}
	return Matrix(result_mat);
}

Matrix Matrix::append(const Matrix& mat, char pos ){
	if((pos == 'l' || pos == 'r') && (this->getDimR() != mat.getDimR())) //check valid dimensions for left/right append
		throw invalid_argument("Couldn't append! Rows dimensions doesn't match ");

	if((pos == 'u' || pos == 'd') && (this->getDimC() != mat.getDimC())) //check valid dimensions for up/down append
		throw invalid_argument("Couldn't append! Columns dimensions doesn't match ");

	vector<vector<double>> result;
	vector<double> vec1;
	vector<double> vec2;

	if(pos == 'l' || pos == 'r'){
		for(int i = 0; i < this->getDimR(); i++){
			vec1 = this->getMat()[i];
			vec2 = mat.getMat()[i];
			if(pos == 'l')
				vec2.insert(vec2.end(), vec1.begin(), vec1.end());
			else
				vec2.insert(vec2.begin(), vec1.begin(), vec1.end());

			result.push_back(vec2);
		}
		return Matrix(result);
	}

	if(pos == 'u'){
		for(int i = 0; i < mat.getDimR(); i++) //iterate over mat2
			result.push_back(mat.getMat()[i]);
		for(int i = 0; i < this->getDimR(); i++) //iterate over mat1
			result.push_back(this->getMat()[i]);
		return Matrix(result);
	}

	if (pos == 'd') {
		for (int i = 0; i < this->getDimR(); i++) //iterate over mat1
			result.push_back(this->getMat()[i]);
		for (int i = 0; i < mat.getDimR(); i++) //iterate over mat2
			result.push_back(mat.getMat()[i]);
		return Matrix(result);
	}
	else
		throw invalid_argument("position invalid");
}

Matrix& Matrix::operator= (const Matrix& mat)
{
	this->dimR = mat.getDimR(); 
	this->dimC = mat.getDimC(); 
	this->mat = mat.getMat();
	this->meanC = mat.getMeanC();
	this->meanR = mat.getMeanR();
	this->rangeR = mat.getRangeR();
	this->rangeC = mat.getRangeC();

	return *this;
};

Matrix& Matrix::remove_row(int row_num){
	if(row_num > this->dimR || row_num < 1)
		throw invalid_argument("Row number is invalid!");
	if(this->dimR == 1)
		throw invalid_argument("Can't delete! There is only one row...");

	this->mat.erase(this->mat.begin()+ row_num - 1);
	this->dimR -= 1;
	return *this;
}

Matrix Matrix::ew_power(int power) const{
	// cout<<">> ew_power\n";
	this->print_mat();
	vector<vector<double>> result = this->mat;
	for(int i = 0; i < this->dimR; i++){
		for (int j = 0; j < this->dimC; j++){
			result[i][j] = pow(result[i][j],power);
			// cout<<result[i][j]<<"\n";
		}
	}
	// cout<<"ew_power >>\n";
	return Matrix(result);
}

Matrix Matrix::scale(double scalar){
	vector<vector<double>> result = this->mat;
	for(int i = 0; i< this->dimR; i++){
		for (int j = 0; j < this->dimC; j++){
			result[i][j] *= scalar;
		}
	}
	return Matrix(result);
}

double Matrix::sum() const{
	vector<vector<double>> result = this->mat;
	double sum = 0.0;
	for(int i = 0; i< this->dimR; i++){
		for (int j = 0; j < this->dimC; j++){
			sum += result[i][j];
		}
	}
	return sum;
}
	
Matrix Matrix::ew_mult(const Matrix& mat) const{
	vector<vector<double>> result = this->mat;
	if(this->getDimC() != mat.getDimC() || this->getDimR() != mat.getDimR()) //check dimensions are the same
		throw invalid_argument("Dimensions aren't valid");

	for(int i = 0; i < this->dimR; i++){
		for(int j = 0; j < this->dimC; j++){
			result[i][j] *= mat.getMat()[i][j]; 
		}
	}

	return Matrix(result);
}