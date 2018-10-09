#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix(string _name, int _height, int _width , int** _param){
	setName(_name);
	width = _width;
	height = _height;
	param = new int* [height];
	int index;
	for (index= 0; index < height; index++) {
		param[index] = new int [width];
	}
	int row, col;
	for (row  = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			param[row][col] = _param[row][col];
		}
	}
}
Matrix::Matrix(const Matrix & matrix){
	setName(matrix.name);
	width = matrix.width;
	height = matrix.height;
	param = new int* [height];
	int index;
	for (index= 0; index < height; index++) {
		param[index] = new int [width];
	}
	int row, col;
	for (row  = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			param[row][col] = 0;
		}
	}
	for (row  = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			param[row][col] = matrix.param[row][col];
		}
	}
}
Matrix::~Matrix(){
	int index;
	for (index = 0; index < height; index++) {
		delete []param[index];
	}
	delete []param;
}
bool Matrix::operator ==(const Matrix& matrix){
	if (height != matrix.height || width != matrix.width) return false;
	int col, row;
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			if (param[row][col] != matrix.param[row][col]) return false;
		}
	}
	return true;
}
bool Matrix::operator !=(const Matrix& matrix){
	if (height == matrix.height || width == matrix.width) return false;
	int check;
	int col, row;
	check = 0;
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			if (param[row][col] != matrix.param[row][col]) check = 1;
		}
	}
	if (check = 1) return true;
	else return false;

}
void Matrix::operator +=(const Matrix& matrix){
	if (height != matrix.height || width != matrix.width) {
		cout << "invalid addition." << endl;
		return;
	}
	int row, col;
	for (row  = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			param[row][col] += matrix.param[row][col];
		}
	}
}
void Matrix::operator -=(const Matrix& matrix){
	if (height != matrix.height || width != matrix.width) {
		cout << "invalid substraction." << endl;
		return;
	}
	int row, col;
	for (row  = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			param[row][col] -= matrix.param[row][col];
		}
	}
}
Matrix Matrix::operator *(const Matrix& matrix){
	if (width != matrix.height) {
		cout << "invalid multiplication." << endl;
		Matrix empty_matrix = Matrix();
		return empty_matrix;
	}
	int col, row, xcol, xrow;
	int index;
	int **arr = new int*[height];
	for (index = 0; index < height; index++) {
		arr[index] = new int[matrix.width];
	}
	for (row  = 0; row < height; row++) {
		for (col = 0; col < matrix.width; col++) {
			arr[row][col] = 0;
		}
	}
	for (xrow = 0; xrow < height; xrow++) {
		for (xcol = 0; xcol < matrix.width; xcol++) {
			for (row = 0, col = 0; row < matrix.height, col < width; row++, col++){
				arr[xrow][xcol] += (param[xrow][col] * matrix.param[row][xcol]);
			}
		}
	}
	Matrix xmatrix = Matrix("newMat",height, matrix.width, arr);
	for (index = 0; index < height; index++) {
		delete []arr[index];
	}
	delete []arr;
	return xmatrix;
}