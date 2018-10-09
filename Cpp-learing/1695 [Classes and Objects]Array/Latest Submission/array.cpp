#include "array.hpp"
typedef int* pointer;
typedef unsigned int size_t;
typedef int data_type;
array::array(size_t size){
	_data = new int[1000];
	_size = size;
}
array::~array(){
	delete [] _data;
}
size_t array::max_size(void){
	return _size;
}
data_type& array::at(const data_type& i){
	return _data[i];
}
data_type& array::front(){
	return _data[0];
}
data_type& array::back(){
	return _data[_size-1];
}
pointer array::data(){
	return array::_data;
}
void array::fill(const data_type& value){
	int index;
	for (index = 0; index < _size; index++){
		_data[index] = value;
	}
}
void array::resize(int newSize){
	_size = newSize;
}
void array::sort(int from, int to){
	int index;
	int poi;
	int swap;
	for (index = from;index < to;index++){
		for (poi = index+1; poi < to; poi++){
			if (_data[index] > _data[poi]) {
				swap = _data[index];
				_data[index] = _data[poi];
				_data[poi] = swap;
			}
		}
	}
}