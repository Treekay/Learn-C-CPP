#include "MyInteger.hpp"
#include <iostream>
#include <cstdlib>
MyInteger::MyInteger(int num){
  value = num;
}
int MyInteger::getValue() const{
  return value;
}
bool MyInteger::isEven() const{
  return !(value % 2);
}
bool MyInteger::isOdd() const{
  return (value % 2);
}
bool MyInteger::isPrime() const{
  return MyInteger::isPrime(value);
}
bool MyInteger::isEven(int num){
   return !(num % 2);
}
bool MyInteger::isOdd(int num){
   return (num % 2);
}
bool MyInteger::isPrime(int num){
  int poi = 2;
  if (num == 1)return false;
  while (poi < num) {
     if (num % poi == 0) return false;
     poi++;
   }
  return true;
}
bool MyInteger::isEven(const MyInteger&seer){
   return !((seer.getValue()) % 2);
}
bool MyInteger::isOdd(const MyInteger&seer){
  return ((seer.getValue()) % 2);
}
bool MyInteger::isPrime(const MyInteger&seer){
  return MyInteger::isPrime(seer.getValue());
}
bool MyInteger::equals(int num){
  if (value == num) return true;
  else return false;
}
bool MyInteger::equals(const MyInteger& seer){
  if (value == seer.value) return true;
  else return false;
}
int MyInteger::parseInt(const std::string& num){
  int parse = std::atoi(num.c_str());
  return parse;
}