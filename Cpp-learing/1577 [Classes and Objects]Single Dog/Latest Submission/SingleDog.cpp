#include "SingleDog.h"
#include <iostream>
#include <cstring>
using namespace std;
int SingleDog::count = 0;
SingleDog::SingleDog(int id_, char* name_):id(id_){
  name = new char[21];
  strcpy(name,name_);
  count++;
}
SingleDog::SingleDog(const SingleDog &other):id(other.id){
  name = new char[21];
  strcpy(name,other.name);
  count++;
}
SingleDog::~SingleDog(){
  delete []name;
  count--;
};
int SingleDog::getCount(){
  return count;
}