#include <cstring>
#include <cstdio>
#include <iostream>

std::string change1(const char* cstr){
  std::string str_;
  str_ = cstr;
  return str_;
}

void change2(std::string str, char* cstr){
  strcpy(cstr,str.c_str());
}