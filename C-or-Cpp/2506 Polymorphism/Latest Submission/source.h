#include <cmath>
class base {
public:
	virtual double area(){}
};

class circle: public base{
public:
  circle (double _r){
    r = _r;
  }
  double area(){
    return r*r*3.1415926535;
  }
private:
  double r;
};

class square: public base{
public:
  square(double _a){
    a = _a;
  }
  double area(){
    return a*a;
  }
private:
  double a;
};

class triangle: public base{
public:
  triangle( double _x, double _y, double _z){
    x = _x;
    y = _y;
    z = _z;
  }
  double area(){
    double s;
    s = 0.5*(x + y + z);
    return sqrt(s*(s-x)*(s-y)*(s-z));
  }
private:
  double x, y, z;
};

class rectangle: public base{
public:
  rectangle(double _x,double _y){
    x = _x;
    y = _y;
  }
  double area(){
    return x*y;
  }
private:
  double x, y;
};