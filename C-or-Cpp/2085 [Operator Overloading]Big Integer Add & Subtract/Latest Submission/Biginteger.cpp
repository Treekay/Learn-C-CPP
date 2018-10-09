 #include "Biginteger.h"
#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;
BigInteger::BigInteger(){
	data_ = NULL;
	size_ = 0;
}
BigInteger::BigInteger(const string& number){
	size_ = number.length();
	data_ = new int[size_];
	int index = 0;
	for (index = 0; index < size_; index++) {
		data_[index] = number[index] - '0';
	}
}
BigInteger::BigInteger(const BigInteger& other){
	size_ = other.size_;
	data_ = new int[size_];
	int index = 0;
	for (index = 0; index < size_; index++) {
		data_[index] = other.data_[index];
	}
}
BigInteger operator+(const BigInteger& left, const BigInteger& right){
	int len;
	if (left.size_ > right.size_) len = left.size_;
	else len = right.size_;
	int _left = 0;
	int _right = 0;
	string sum = "";
	int add = 0;
	for (int index1 = 0, index2 = 0; index1 <len || index2  < len; index1++, index2++){
		if (left.size_ > index1) _left = left.data_[left.size_-index1-1];
		else _left = 0;
		if (right.size_ > index2) _right = right.data_[right.size_-index2-1] ;
		else _right = 0;
		sum += ((_left + _right + add )%10 + '0');
		add = (_left + _right + add)/10;
	}
	if (add == 1) sum += 1;
	reverse(sum.begin(),sum.end()); 
	BigInteger c(sum);
	return c;
}
BigInteger operator-(const BigInteger& left, const BigInteger& right){
	int len;
	len = left.size_;
	int _left = 0;
	int _right = 0;
	string diff = "";
	int sub = 0;
	for (int index1 = 0, index2 = 0; index1 <len ||index2  <len; index1++, index2++){
		if (left.size_ > index1) _left = left.data_[left.size_-index1-1];
		else _left = 0;
		if (right.size_ > index2) _right = right.data_[right.size_-index2-1] ;
		else _right = 0;
		if (_left < _right|| (_left - _right -sub )< 0) {
			diff += ((_left - _right - sub +10 )%10 + '0');
			sub = 1;
		}
		else {
			if (((_left - _right - sub )%10 ) != 0 || left.size_ != index1+1) diff += ((_left - _right - sub )%10 + '0');
			else if (((_left - _right - sub )%10 ) == 0 && left.size_ == index1+1) break;
			sub = 0;
		}
	}
	reverse(diff.begin(),diff.end()); 
	BigInteger c(diff);
	return c;
}
ostream& operator<<(ostream& out, const BigInteger& Bint){
	for (int index = 0;index < Bint.size_; index++){
		out << (Bint.data_[index]);
	}
	return out; 
}
BigInteger::~BigInteger(){
	delete [] data_;
}