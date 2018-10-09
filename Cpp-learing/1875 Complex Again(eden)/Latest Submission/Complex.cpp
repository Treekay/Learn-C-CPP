#include <iostream>
#include "Complex.hpp"
using namespace std;
 Complex::Complex(double x, double y){
 	SetReal(x);
   	SetImag(y);
 }
void Complex::operator = (const Complex& a){
	real = a.real;
	imag = a.imag;
}
Complex Complex::operator + (const Complex& a){
	Complex c;
	c.real = real + a.real;
	c.imag = imag + a.imag;
	return c;
}
Complex Complex::operator - (const Complex& a){
	Complex c;
	c.real = real - a.real;
	c.imag = imag - a.imag;
	return c;
}
Complex Complex::operator * (const Complex& a){
	Complex c;
	c.real = real * a.real - imag * a.imag;
	c.imag = imag * a.real + real * a.imag;
	return c;
}
Complex Complex::operator / (const Complex& a){
	Complex c;
	c.real = (real*a.real + imag*a.imag)/(a.real*a.real + a.imag*a.imag);
	c.imag = (imag*a.real - real*a.imag)/(a.real*a.real + a.imag*a.imag);
	return c;
}
void Complex::operator += (const Complex& a){
	real += a.real;
	imag += a.imag;
}
void Complex::operator -= (const Complex& a){
	real -= a.real;
	imag -= a.imag;
}
void Complex::operator *= (const Complex& a){
	double _real, _imag;
	_real = real * a.real - imag * a.imag;
	_imag = imag * a.real + real * a.imag;
	real = _real;
	imag = _imag;
}
void Complex::operator /= (const Complex& a){
	double _real, _imag;
	_real = (real*a.real + imag*a.imag)/(a.real*a.real + a.imag*a.imag);
	_imag = (imag*a.real - real*a.imag)/(a.real*a.real + a.imag*a.imag);
	real = _real;
	imag = _imag;
}
bool Complex::operator == (const Complex& a){
	if (real == a.real && imag == a.imag) return true;
	else return false;
}
bool Complex::operator != (const Complex& a){
	if (real != a.real || imag != a.imag) return true;
	else return false;
}