#include <iostream>
#include "date.hpp"

Date::Date (){
 setDate(2017,1,28);
}

Date::Date (int year_,int month_,int day_) {
 setDate(year_,month_,day_);
}
void Date::normalize(){
if(month >12) {
    if (month % 12 == 0) {
         year += month /12 -1;
         month = 12;
       }
  else {
     year += month /12;
     month %= 12;
   }
}
  while(day > daysOfMonth(year,month)){
     day -= daysOfMonth(year,month);
     month ++;
     if (month > 12) {
    	year++;
   	 	month -= 12;
	}
   }
}
bool Date::equals(const Date&date) const{
  if (year == date.year && month == date.month && day == date.day) return true;
  else return false;
}
bool Date::smallerThan(const Date&date) const{
  if (year < date.year) return true;
  else if (year > date.year) return false;
  else {
     if (month <date.month) return true;
     else if (month > date.month) return false;
     else {
           if (day < date.day) return true;
           else if (day >= day) return false;
         }
   }
}