 #include "FUN.hpp"
#include <iostream>
#include <cstring>
using namespace std;

FUN::FUN(char *s){
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}

FUN::FUN(const FUN& C){
  str = new char[strlen(C.str) + 1];
  strcpy(str, C.str);
}

void FUN::show(){
  int len = strlen(str);
  for (int index = 0; index < len; index++) {
    cout << str[index];
  }
  cout <<endl;
}