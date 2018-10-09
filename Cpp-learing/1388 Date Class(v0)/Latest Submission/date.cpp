#include "date.hpp"
int Date::year() const{
  return year_;
}
int Date::month() const{
  return month_;
}
int Date::day() const {
  return day_;
}
void Date::setDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}
int Date::daysOfMonth(int year, int month) const {
  if (month == 2) {
    if (year%4 == 0 && year%100 != 0 || year%400 == 0) return 29;
    else return 28;
   }
  else if (month == 4||month == 6||month == 9||month == 11) return 30;
  return 31;
}
void Date::increment(){
  if (day_ < daysOfMonth(year_,month_)) day_++;
  else {
     if (month_ == 12) {
           year_++;
           month_ = 1;
         }
     else { 
        month_++;
         }
    day_ = 1;
   }
}
void Date::decrement(){
  if (day_ > 1) day_--;
  else {
      if (month_ == 1) {
             year_--;
             month_ = 12;
           }
      else month_--;
      day_ = daysOfMonth(year_,month_);
     }
}