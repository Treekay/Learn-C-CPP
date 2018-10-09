#include <iostream>
#include "set.hpp"

Set::Set():members{}{
  size = 0;
}
Set::Set(int* m, int s){
  int index;
  for (index = 0,size = 0; index < s; index++){
     if (!isInSet(*(m+index))) {
           members[size] = *(m + index);
           size++;
         }
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
    
    // return set.
int* Set::getMembers(){
  return members;
}
    
    // return size of set.
int Set::getSize(){
  return size;
}
 
    // return false if element not in the set, or return true.
bool Set::isInSet(int e){
  int index;
  for (index = 0; index < size; index++) {
     if (members[index] == e) return true;
   }
  return false;
}