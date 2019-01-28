#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class Matrix{
    private:
        int dimR; //number of rows
        int dimC; //number of columns
        vector<vector<double>> mat; //matrix
        vector<double> meanR; //mean of each row
        vector<double> meanC; //mean of each column
        vector<double> rangeR; //range of each row
        vector<double> rangeC; //range of each column


    public:
        Matrix(); //def constructor
        Matrix(int dimR, int dimC); //constructor
        Matrix(const vector<vector<double>>& mat); //constructor 2
        Matrix(const vector<double>& mat); //constructor 3
        Matrix(const Matrix& mat); //constructor 4


        void init_mat(int dimR, int dimC); //initialize a matrix
        int getDimR() const;
        int getDimC() const;
        vector<double> getMeanR() const;
        vector<double> getMeanC()const;
        vector<double> getRangeR() const;
        vector<double> getRangeC() const;
        vector<vector<double>> getMat() const;
        void print_mat() const; //print the matrix instance
        Matrix transpose() const;
        Matrix append(const Matrix& mat, char pos); //append mat in the specified position {left,right,up,down}
        Matrix& remove_row(int row_num); //remove row from original matrix
        Matrix scale(double scalar);
        Matrix ew_power(int power) const;
        Matrix ew_mult(const Matrix& mat) const;
        void normalize(const int axis); //normalize the values according the specified axis(0-rows,1-columns)
        double sum() const;
        Matrix& operator=(const Matrix& mat);
        friend Matrix operator*(const Matrix& mat1, const Matrix& mat2);
        friend Matrix operator/(const Matrix& mat1, const Matrix& mat2);
        friend Matrix operator-(const Matrix& mat1, const Matrix& mat2);

};

