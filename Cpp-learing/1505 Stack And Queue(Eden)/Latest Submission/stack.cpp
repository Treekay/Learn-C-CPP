#include "stack.hpp"
#include <iostream>
void stack::push(int num){
  if (top < max_size -1) {
     top++;
     storage[top] = num;
   }
}
void stack::pop(void){
  if (top > -1) top--;
}
int stack::peek(void){
  return storage[top];
}
bool stack::isEmpty(void){
  if (top == -1) return true;
  else return false;
}
bool stack::isFull(void){
  if (top == max_size-1) return true;
  else return false;
}
void stack::clear(void){
  top = -1;
}