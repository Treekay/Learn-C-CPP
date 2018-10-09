#include "date.h"
#include <stdio.h>
#include <stdlib.h>

Date* CreateDate(int year, int month, int day){
  Date* date = (Date*)malloc(sizeof(Date));
  date->year = year;
  date->month = month;
  date->day = day;
  return date;
}

int daysOfMonth(int year, int month) {
  if (month == 2) {
    if (year%4 == 0 && year%100 != 0 || year%400 == 0) return 29;
    else return 28;
   }
  else if (month == 4||month == 6||month == 9||month == 11) return 30;
  return 31;
}
void DestroyDate(Date** p){
  free(*p);
  *p = NULL;
}

Date* CopyDate(const Date* date){
  Date* date1 = (Date*)malloc(sizeof(Date));
  date1->year = date->year ;
  date1->month = date->month ;
  date1->day = date->day ;
  return date1;
}
int GetYear(const Date* date){
  int year1 = date->year;
  return year1;
}
int GetMonth(const Date* date){ 
  int month1 = date->month;
  return month1;
}
int GetDay(const Date* date){ 
  int day1 = date->day;
  return day1;
}
void SetYear(Date* date, int year){date->year = year;}
void SetMonth(Date* date, int month){date->month = month;}
void SetDay(Date* date, int day){date->day = day;}
void SetDate(Date* date, int year, int month, int day){
  date->year = year;
  date->month = month;
  date->day = day;
}

char* GetDateString(const Date* date){
  char * dateString = (char*)malloc(11);
  sprintf(dateString,"%04d-%02d-%02d",date->year,date->month,date->day);
  return dateString;
}

void DestroyDateString(char** p){
  free(*p);
  *p = NULL;
}

void IncreaseDate(Date* date){
  if (date->day < daysOfMonth(date->year,date->month)) date->day++;
  else {
     if (date->month == 12) {
           date->year++;
           date->month = 1;
         }
     else date->month++;
     date->day = 1;
   }
}

void DecreaseDate(Date* date){
  if (date->day > 1) date->day--;
  else {
      if (date->month == 1) {
             date->year--;
             date->month = 12;
           }
      else date->month--;
      date->day = daysOfMonth(date->year,date->month);
     }
}