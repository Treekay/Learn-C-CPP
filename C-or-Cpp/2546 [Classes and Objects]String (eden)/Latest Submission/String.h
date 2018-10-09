#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class String {  
public:  
	 String(){
     _buff = NULL;
     _size = 0;
   }
  explicit String(const char *src){
    _buff = new char[strlen(src) + 1];
    strcpy(_buff, src);
    _size = strlen(src);
  }
  String(const String &src) {
    _buff = new char[strlen(src.c_str()) + 1];
    strcpy(_buff, src.c_str());
    _size = strlen(src.c_str());
  }

  ~String(){
    delete [] _buff;
  }

  String& operator =(const String& src){
    char* poi = _buff;
    _buff = new char[strlen(src.c_str()) + 1];
    strcpy(_buff, src.c_str());
    _size = strlen(src.c_str());
    delete [] poi;
    return *this;
  }  
  const char* c_str() const{
    //return _buff  
    return _buff;
  }
  inline char& operator[](int i){
    return _buff[i];
  }

  friend ostream& operator <<(ostream& os, const String& src){
    for (int index = 0; index < src._size; index++){
      os << src._buff[index];
    }
    return os;
  }

private:  
  char *_buff;  
  int _size;  
};