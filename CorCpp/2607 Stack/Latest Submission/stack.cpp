 #include "stack.hpp"


stack::~stack(){
 delete [] storage;
}
void stack::push(E ele){
 if (!isFull()) storage[size++] = ele;
 else return;
}
void stack::pop(){
 if (!isEmpty()) storage[--size] = 0;
}
E stack::top(){
 return storage[size-1];
}
bool stack::isEmpty(){
 if (size == 0) return true;
 else return false;
}
bool stack::isFull(){
 if (size == max_size) return true;
 else return false;
}
void stack::clear(){
 int num = size;
 for (int index = 0; index < num; index++){
  pop();
 }
}