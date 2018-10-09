#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
class Date {
  private:
    int _year;
    int _month;
    int _day;
  public:
    Date(){
      _year = 0;
      _month = 0;
      _day = 0;
    }
    Date(int y, int m, int d){
      _year = y;
      _month = m;
      _day = d;
    }
    Date(string dateString){// the format of dateString is like "2017-5-7"
      char y[5] = {0};
      char m[3] = {0};
      char d[3] = {0};
      int poi = 0;
      for (int index = 0; index < 4,dateString[poi] != '-'; index++, poi++){
        y[index] = dateString[poi];
      }
      poi++;
      for (int index = 0; index < 7,dateString[poi] != '-'; index++, poi++){
        m[index] = dateString[poi];
      }
      poi++;
      for (int index = 0; index < 10; index++, poi++){
        d[index] = dateString[poi];
      }
      _year = atoi(y);
      _month = atoi(m);
      _day = atoi(d);
    }
    int getYear() const{
      return _year;
    }
    void setYear(int y){
      _year = y;
    }
    int getMonth() const{
      return _month;
    }
    void setMonth(int m){
      _month = m;
    }
    int getDay() const{
      return  _day;
    }
    void setDay(int d){
      _day = d;
    }
    bool operator==(Date& other) const{
      if (other.getYear() == _year && other.getMonth() == _month && other.getDay() == _day) return true;
      else  return false;
    }
    bool operator<(Date& other) const{
      if (_year > other.getYear()) return false;
      else if (_year < other.getYear()) return true;
      else {
          if (_month > other.getMonth()) return false;
          else if (_month < other.getMonth()) return true;
          else {
                if (_day >= other.getDay()) return false;
              else if (_day < other.getDay()) return true;
             }
      }
    }
    bool operator>(Date& other) const{
      if (_year > other.getYear()) return true;
      else if (_year < other.getYear()) return false;
      else {
          if (_month > other.getMonth()) return true;
          else if (_month < other.getMonth()) return false;
          else {
                if (_day > other.getDay()) return true;
              else if (_day < other.getDay()) return false;
             }
      }
    }
    std::string toString() const{ // return a string like "year-month-day"
      const int length_of_date_string = 10;

      char date_string[length_of_date_string + 1] = {0};
      snprintf(date_string,
              length_of_date_string + 1,
              "%d-%d-%d",
              _year, _month, _day);

      return std::string(date_string);  
    }
};

#endif