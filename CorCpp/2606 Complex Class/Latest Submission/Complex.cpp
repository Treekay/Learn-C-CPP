 #include <iostream>
using namespace std;
class Complex{
 private:
  double real;
  double imag;
 public:
  Complex(double x=0, double y=0){
    real = x;
    imag = y;
  }
  friend ostream &operator <<(ostream& os, const Complex&c){//e.g 2+3i  -2-5i
    	if (c.real == 0 && c.imag == 0) os << '0';
    else if (c.real != 0 && c.imag == 0) os << c.real;
    else if (c.real == 0 && c.imag != 0) os << c.imag << 'i';
    else if (c.real != 0 && c.imag != 0) {
      os << c.real;
      if (c.imag > 0) os << '+';
      if (c.imag == 1) os << 'i';
      else if (c.imag == -1) os << "-i";
      else os << c.imag << 'i';
    }
    return os;
  }
  friend istream &operator >>(istream& is, Complex &c){
    is >> c.real >> c.imag;
    return is;
  }
  Complex operator +(const Complex &obj){
     Complex poi(real,imag);
     poi.real += obj.real;
     poi.imag += obj.imag;
     return poi;
  }
  Complex operator -(const Complex &obj){
    Complex poi(real,imag);
     poi.real -= obj.real;
     poi.imag -= obj.imag;
     return poi;
  }
  Complex operator *(const Complex &obj){
    Complex poi(real, imag);
     int _real;
     int _imag;
     _real = poi.real*obj.real - poi.imag*obj.imag;
     _imag = poi.real*obj.imag + poi.imag*obj.real;
     poi.real = _real;
     poi.imag = _imag;
     return poi;
  }
};