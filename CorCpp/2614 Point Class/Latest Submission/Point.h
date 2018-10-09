#ifndef POINT_H
#define POINT_H
#include <iostream>
using std::cout;
using std::endl;

class Point
{
private:
    int *data;
    int dimension;
public:
    Point(int _dimension){
        dimension = _dimension;
        data = NULL;
    }
    Point(int* _data,int _dimension){
        dimension = _dimension;
        data = new int[dimension];
        for (int index = 0; index < dimension; index++){
            data[index] = _data[index];
        }
    }
    Point operator+(const Point& other){
        Point newone(dimension > other.dimension ? dimension : other.dimension);
        if (dimension > other.dimension){
            newone.data = new int[dimension];
            for (int index1 = 0; index1 < other.dimension; index1++){
                newone.data[index1] = data[index1] + other.data[index1];
            }
            for (int index2 = other.dimension; index2 < dimension; index2++){
                newone.data[index2] = data[index2];
            }
        }
        else if (dimension == other.dimension){
            newone.data = new int[dimension];
            for (int index = 0; index < dimension; index++){
                newone.data[index] = data[index] + other.data[index];
            }
        }
        else if (dimension < other.dimension){
            newone.data = new int[other.dimension];
            for (int index1 = 0; index1 < dimension; index1++){
                newone.data[index1] = data[index1] + other.data[index1];
            }
            for (int index2 = dimension; index2 < other.dimension; index2++){
                newone.data[index2] = other.data[index2];
            }
        }
        return newone;
    }
    Point operator-(const Point& other){
        Point newone(dimension > other.dimension ? dimension : other.dimension);
        if (dimension > other.dimension){
            newone.data = new int[dimension];
            for (int index1 = 0; index1 < other.dimension; index1++){
                newone.data[index1] = data[index1] - other.data[index1];
            }
            for (int index2 = other.dimension; index2 < dimension; index2++){
                newone.data[index2] = data[index2];
            }
        } 
        else if (dimension == other.dimension){
            newone.data = new int[dimension];
            for (int index = 0; index < dimension; index++){
                newone.data[index] = data[index] - other.data[index];
            }
        }
        else if (dimension < other.dimension){
            newone.data = new int[other.dimension];
            for (int index1 = 0; index1 < dimension; index1++){
                newone.data[index1] = data[index1] - other.data[index1];
            }
            for (int index2 = dimension; index2 < other.dimension; index2++){
                newone.data[index2] = -other.data[index2];
            }
        }
        return newone;
    }
    Point& operator=(const Point& other){
        if (data != other.data){
            delete [] data;
            dimension = other.dimension;
            data = new int[dimension];
            for (int index = 0; index < dimension; index++){
                data[index] = other.data[index];
            }
        }
        return *this;
    }
    ~Point(){
        delete [] data;
        data = NULL;
        dimension = 0;
    }
    void print(){
        cout << "(";
        for (int index = 0; index < dimension; index++){
            cout << data[index];
            if (index != dimension -1) cout << ",";
        }
        cout << ")" <<endl;
    }
};

#endif