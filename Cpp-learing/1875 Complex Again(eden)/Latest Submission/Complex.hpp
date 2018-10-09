#include <iostream>
using namespace std;
class Complex {
      //A friend function to print Complex numbers like a+bi where a is the real part and b is the imaginary part
	friend ostream& operator << (ostream & os,const Complex&  num){
		
		if (num.imag > 0) {
			if (num.real != 0) os << num.real << '+';
			os << num.imag << 'i' <<endl;
		}
		else if (num.imag < 0) {
			if (num.real != 0) os << num.real;
			os << num.imag << 'i'<< endl;
		}
		else if (num.imag == 0) os << num.real;
	}
public:
   Complex(double x = 0.0, double y = 0.0);

   //Some function about operator overloading.
   void operator = (const Complex& a);
   Complex operator + (const Complex& a);
   Complex operator - (const Complex& a);
   Complex operator * (const Complex& a);
   Complex operator / (const Complex& a);
   void operator += (const Complex& a);
   void operator -= (const Complex& a);
   void operator *= (const Complex& a);
   void operator /= (const Complex& a);
   bool operator == (const Complex& a);
   bool operator != (const Complex& a);
   void SetReal(double re){real = re;}
   void SetImag(double im){imag = im;}
private:
   double real; 
   double imag; 
};