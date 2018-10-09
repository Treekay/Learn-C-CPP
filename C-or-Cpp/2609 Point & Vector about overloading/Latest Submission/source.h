 #ifndef _SOURCE_H
#define _SOURCE_H
#include "iostream"
using namespace std;

class Vector{
public:
    Vector(): x(0) , y(0){}
    Vector(int a, int b){
        x = a;
        y = b;
    }
    Vector operator+ (const Vector& vec){
        return Vector(x + vec.x, y + vec.y);
    }
    Vector& operator= (const Vector& vec){
        x = vec.x;
        y = vec.y;
        return *this;
    }
    int getx(){
        return x;
    }
    int gety(){
        return y;
    }
    friend ostream& operator<< (ostream& os, const Vector& vec){
        os << vec.x << " " << vec.y ;
        return os;
    }
private:
    int x;
    int y;
};

class Point{
public:
    Point(): x(0), y(0){}
    Point(int a, int b){
        x = a;
        y = b;
    }
    Point operator+ (const Point& poi){
        return Point(x + poi.x, y + poi.y);
    }
    Point operator+ (Vector vec){
        return Point(x + vec.getx(), y + vec.gety());
    }
    Point& operator= (const Point& poi){
        x = poi.x;
        y = poi.y;
        return *this; 
    }
    friend ostream& operator<< (ostream& os, const Point& poi){
        os << poi.x << " " << poi.y ;
        return os;
    }
private:
    int x;
    int y;
};

#endif