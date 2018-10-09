#include <string>
#include <iostream>
using namespace std;
class Object{
private:
  string instance;
public:
  Object(){
    instance = "Object";
  }
  virtual string getinstance(){
    return instance;
  }
};

class Animal: public Object{
private:
  string instance;
public:
  Animal(){
    instance = "Animal";
  }
  virtual string getinstance(){
    return instance;
  }
};

class Dog: public Animal{
private:
  string instance;
public:
  Dog(){
    instance = "Dog";
  }
  string getinstance(){
    return instance;
  }
};
class Cat: public Animal{
private:
  string instance;
public:
  Cat(){
    instance = "Cat";
  }
  string getinstance(){
    return instance;
  }
};

class Vehicle: public Object{
private:
  string instance;
public: 
  Vehicle(){
    instance = "Vehicle";
  }
  virtual string getinstance(){
    return instance;
  }
};

class Bus: public Vehicle{
private:
  string instance;
public: 
  Bus(){
    instance = "Bus";
  }
  string getinstance(){
    return instance;
  }
};
class Car: public Vehicle{
private:
  string instance;
public: 
 		Car(){
    instance = "Car";
  }
  string getinstance(){
    return instance;
  }
};

/*
 * 返回这个对象实例实际的类型名
 * 例如: Object *obj = new Bus();
 * 则 instaceOf(obj) == "Bus"
 * 若 obj == NULL
 * 则 instanceOf(obj) == "NULL"
 */
string instanceOf(Object *obj){
  if (obj == NULL) return "NULL";
  else return obj->getinstance();
}