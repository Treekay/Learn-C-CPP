 #include <iostream>
#include <cstdlib>
#include <cstddef>
#include "ArrayList.hpp"
using namespace std;
ArrayList::ArrayList() {
 storage = new int[DEFAULT_MAX_SIZE];
 _maxsize = DEFAULT_MAX_SIZE;
 _size = 0;
}
  ArrayList::~ArrayList() {
   if (storage != NULL)
    delete [] storage;
   storage = NULL;
  }
void  ArrayList::add(E e) {
 if (_size < _maxsize)
  storage[_size++] = e;
 else {
      extend();
      storage[_size++] = e;
 }
}
  void  ArrayList::remove(E e) {
   for (int i = 0; i < _size; ++i) {
     if (storage[i] == e) {
      for (int j = i; j < _size - 1; ++j)
          storage[j] = storage[j + 1];
      --i;
      --_size;
      }
   }
  }
  void  ArrayList::clear() {
   _size = 0;
  }

  bool  ArrayList::contain(E e) {
   for (int i = 0; i < _size; ++i)
      if (storage[i] == e)
       return true;
    return false;
  }
  bool  ArrayList::isEmpty() {
   if (_size == 0)
    return true;
   return false;
  }
  E&  ArrayList::operator[](int index) {
   return storage[index];
  }
  E&  ArrayList::get(int index) {
   return storage[index];
  }
  int  ArrayList::indexOf(E element) {
    for (int i = 0; i < _size; ++i)
      if (storage[i] == element)
       return i;
    return -1;
  }
  int  ArrayList::size() {
   return _size;
  }

  void ArrayList::extend() {
   _maxsize *= extend_factor;
   int *new_p = new int[_maxsize];
   for (int i = 0; i < _size; ++i)
      new_p[i] = storage[i];
    delete [] storage;
    storage = new_p;
  }