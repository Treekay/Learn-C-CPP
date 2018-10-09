 #include "Vector.h"
#include <iostream>
using namespace std;


Vector::Vector(string _name, int len, int num[] ){
	this->name = _name;
	this->dimension = len;
	this->param = new int [dimension];
	for (int index = 0; index < dimension; index++){
		this->param[index] = num[index];
	}
	cout << "construct a vector called " << this->name << "." <<endl;
}

Vector::Vector(const Vector &otherVec){
	this->name = otherVec.name;
	this->dimension = otherVec.dimension;
	this->param = new int[dimension];
	for (int index = 0; index < dimension; index++){
		this->param[index] = otherVec.param[index];
	}
	cout << "copy a vector called " << this->name << "." << endl;
}
Vector::~Vector(){
	delete [] param;
	cout << "release memory from a vector called " << this->name << "." << endl;
}
void Vector::isEqual(const Vector &otherVec){
	if (otherVec.name == this->name) cout << "same name,";
	else cout << "different name,";

	if (this->dimension != otherVec.dimension) {
		cout <<" different value." << endl;
			return;
	}
	for (int index = 0; index < otherVec.dimension; index++){
		if (this->param[index] != otherVec.param[index]) {
			cout <<" different value." << endl;
			return;
		}
	}
	cout <<" same value."<<endl;
}
void Vector::setName(string str){
	this->name = str;
}
void Vector::print(){
	cout << this->name;
	cout <<'(';
	for (int index = 0; index < dimension; index++) {
		cout << this->param[index];
		if (index + 1 != dimension) cout << ", ";
	}
	cout << ')';
	cout <<endl;
}