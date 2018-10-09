#include "String.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// overload operators
char& String::operator[](const int &index){
    return _buff[index];
}
void String::operator=(const String &other){
     clear ();
    _length =strlen(other._buff);
    _size = _length + 1;
    _buff = new char [_size];
    strcpy (_buff, other._buff);
    _buff[_length] = '\0';
}
void String::operator=(const char *src){
    clear ();
    _length =strlen(src);
    _size = _length + 1;
    _buff = new char [_size];
    strcpy (_buff, src);
    _buff[_length] = '\0';
}
String String::operator+(const String &other) const{
    int len = _size + other._size;
    char out[len];
    strcpy (out, _buff);
    strcat (out, other._buff);
    String output(out);
    return output;
}
bool String::operator<(const String &other) const{
    return compare(other) == -1;
}
bool String::operator<=(const String &other) const{
    return compare(other) != 1;
}
bool String::operator>(const String &other) const{
    return compare(other) == 1;
}
bool String::operator>=(const String &other) const{
    return compare(other) != -1;
}
bool String::operator==(const String &other) const{
    return compare(other) == 0;
}
bool String::operator!=(const String &other) const{
    return compare(other) != 0;
}
String::String(){
    _buff = NULL;
    _length = 0;
    _size = 0;
}
String::String(const char *src){
     _buff = NULL;
    _length = strlen(src);
    _size = _length + 1;
    _buff = new char [_size];
    strcpy (_buff, src);
    _buff[_length] = '\0';
}
String::String(const String &src){
    if (_buff != NULL) clear ();
    _length =strlen(src._buff);
    _size = _length + 1;
    _buff = new char [_size];
    strcpy (_buff, src._buff);
    _buff[_length] = '\0';
}
// destructor
String::~String(){
    if (_buff != NULL) delete [] _buff;
}
// member methods
void String::assign(const char *src){
    clear ();
    _length =strlen(src);
    _size = _length + 1;
    _buff = new char [_size];
    strcpy (_buff, src);
    _buff[_length] = '\0';
}
void String::append(const char &other){
    if (_buff == NULL) {
        char cop[2];
         cop[0] = other;
         cop[1] = '\0';
          clear();
        _length = strlen(cop);
        _size = _length + 1;
        _buff = new char [_size];
        strcpy (_buff, cop);
        _buff[_length] = '\0';
    }
    else {
        char cop[_size+1];
        strcpy (cop, _buff);
        cop[_length] = other;
        cop[_size] = '\0';
         clear();
        _length = strlen(cop);
        _size = _length + 1;
        _buff = new char [_size];
        strcpy (_buff, cop);
        _buff[_length] = '\0';
    }
}
void String::clear(){
    if (_buff != NULL) delete [] _buff;
    _length = 0;
    _size = 0;
    _buff = NULL;
}
int String::compare(const String &other) const{
    if (strcmp(_buff,other._buff) < 0) return -1;
    else if (strcmp(_buff,other._buff) == 0) return 0;
    else if (strcmp(_buff,other._buff) > 0) return 1;
}
const char* String::c_str() const{
    return _buff;
}
bool String::empty() const{
    if (_length != 0) return false;
    else return true;
}
int String::find(const String &other, int pos) const{
    string test;
    for (int index = pos; index < _length; index++) {
        test += _buff[index];
    }
    pos = test.find(other._buff);
    if (pos != -1) return pos;
    else return _length;
}
int String::length() const{
    return _length;
}
String String::substr(const int &pos, const int &count) const{
    int len = count +1;
    char out[len];
    int index;
    for (index = 0; index < count; index++){  
        out[index] = _buff[pos + index];
    }
    out[index] = '\0';
    String output(out);
    return output;
}
// friend methods
std::ostream& operator<<(std::ostream& out, const String &str){
    for (int index = 0; index  < str._length; index++) {
        out << str._buff[index];
    }
    return out;
}