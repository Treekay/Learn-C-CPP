#include "Set.hpp"
#include <iostream>
using namespace std;
// Create an empty set.
Set::Set():members(){
  size = 0;
}
// Create an set with some element.
Set::Set(int* m, int s){
  size = s;
  int index;
  for (index = 0; index < size; index++) {
     members[index] = m[index];
   }
}
// Copy Constructor
Set::Set(Set const &s){
  size = s.size;
  int index;
  for (index = 0; index < size; index++) {
     members[index] = s.members[index];
   }
}
    
// append a element to set.
// If element in the set, return false.
// Or insert in set and return true.
bool Set::append(int e){
  if (isInSet(e)) return false;
  else {
     members[size] = e;
     size++;
   }
  return true;
}
    
// remove a element by its value from set.
// If element in the set, then remove it and return true.
// Or return false.
bool Set::remove(int e){
  int index;
  for (index = 0; index < size; index++) {
     if (members[index] == e) {
       for (; index < size-1; index++){
               members[index] = members[index+1];
             }
      size--;
       return true;
         }
   }
  return false;
}
    
// return true if the set is empty, or return false.
bool Set::isEmptySet(){
  int index;
  for (index = 0; index < size; index++) {
     if (members[index] != 0) return false;
   }
  return true;
}
    
// return true if the element e is in the set, or return false.
bool Set::isInSet(int e){
  int index;
  for (index = 0; index < size; index++) {
     if (members[index] == e) return true;
   }
  return false;
}
    
// & is intersection of two set
Set Set::operator&(const Set &s){
  Set qie = Set();
  int index;
  int poi;
  for (index = 0; index < s.size; index++ ) {
     for (poi = 0; poi < size; poi++ ) {
        if (s.members[index] == members[poi]) qie.members[qie.size++] = s.members[index];
       }
   }
  return qie;
}
// | is union of two set
Set Set::operator|(const Set &s){
  Set huo = Set();
  int index;
  int poi;
  int check;
  for (index = 0; index < size; index++) {
      huo.members[huo.size++] = members[index];
  }
  for (index = 0; index < s.size; index++) {
    check = 0;
    for (poi = 0; poi < size; poi++){
      if (s.members[index] == members[poi]) {
          check = 1;
          break;
      }
    }
    if (check != 1) huo.members[huo.size++] = s.members[index];
  }
  return huo;
}
// A - B is the complement of B with respect to A
Set Set::operator-(const Set &s){
  Set fei = Set();
  int index;
  int poi;
  int check;
  for (index = 0; index < size; index++ ) {
      check = 0;
      for (poi = 0; poi < s.size; poi++ ) {
          if (s.members[poi] == members[index]) {
              check = 1;
             break;
          }
      }
      if (check != 1) fei.members[fei.size++] = members[index];
   }
   return fei;
}
// A + B is their symmetric difference. A + B = (A - B) | (B - A)
Set Set::operator+(const Set &s){
  Set add = Set();
  int index;
  int poi;
  int check;
  for (index = 0; index < size; index++ ) {
      check = 0;
      for (poi = 0; poi < s.size; poi++ ) {
          if (s.members[poi] == members[index]) {
              check = 1;
             break;
          }
      }
      if (check != 1) add.members[add.size++] = members[index];
   }
   for (index = 0; index < s.size; index++ ) {
      check = 0;
      for (poi = 0; poi < size; poi++ ) {
          if (s.members[index] == members[poi]) {
              check = 1;
             break;
          }
      }
      if (check != 1) add.members[add.size++] = s.members[index];
   }
  return add;
}
    
// return set.
int* Set::getMembers(){
  return members;
}
    
// return size of set.
int Set::getSize(){
  return size;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                