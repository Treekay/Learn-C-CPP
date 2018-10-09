#include "Complex.hpp"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

Complex::Complex( double real, double imaginary ) {
 setComplexNumber( real, imaginary );
 }

Complex Complex::add( const Complex &right ) {
 realPart += right.realPart;
 imaginaryPart += right.imaginaryPart;
 return *this;
}

Complex Complex::subtract( const Complex &right ) {
 realPart -= right.realPart;
 imaginaryPart -= right.imaginaryPart;
 return *this;
} 

void Complex::printComplex() {
 cout << '(' << realPart << ", " << imaginaryPart << ')';
} 

void Complex::setComplexNumber( double rp, double ip ) {
 realPart = rp;
 imaginaryPart = ip;
} 