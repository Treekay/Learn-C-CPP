#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

class NumberParseException {};
bool isNumber(const char* str) {
  using namespace std;
  if (str == NULL) return false;
  int len = strlen(str);
  if (len == 0) return false;
  bool isaNumber = false;
  char ch;
  for (int i = 0; i < len; i++) {
    if (i == 0 && (str[i] == '-' || str[i] == '+' )) continue;
    if (isdigit(str[i])){
      isaNumber = true;
    }
    else {
      isaNumber = false;
      break;
    	}
  	}
    return isaNumber;
}
int parseNumber(const char *str) throw(NumberParseException){
   if (!isNumber(str)){
     throw NumberParseException();
   }
  return atoi(str);
}