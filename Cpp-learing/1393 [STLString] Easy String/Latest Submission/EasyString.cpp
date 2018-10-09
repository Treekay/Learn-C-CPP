#include <string>
#include <cstdlib>
#include "EasyString.hpp"
void Assign(char * &str, int &length){
  str = new char[length+1];
}
void AddTwo(string &res, char * &str0, char * &str1){
  res += str0;
  res += str1;
  delete [] str0;
  delete [] str1;
}