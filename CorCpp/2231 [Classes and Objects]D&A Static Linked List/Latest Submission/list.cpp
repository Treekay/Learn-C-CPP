 #include "list.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

typedef int data_type;
typedef int pointer;
typedef unsigned int size_type;
const pointer list::nullpointer;

list::list(){
    _size = 0;
    head = nullpointer;
    empty_head = 0;
    for (int index = 0; index < MAX_STORAGE - 1; index++){
    	storage[index].data =  0;
    	storage[index].next = index + 1;
    }
    storage[MAX_STORAGE - 1].data = 0;
    storage[MAX_STORAGE - 1].next = nullpointer;
}
list::list(const list& another){
	_size = another._size;
	head = another.head;
	empty_head = another.empty_head;
	for (int index = 0; index < MAX_STORAGE; index++) {
		storage[index] = another.storage[index];
	}
}
list& list::operator=(const list& another){
	clear();
	_size = another._size;
	head = another.head;
	empty_head = another.empty_head;
	for (int index = 0; index < MAX_STORAGE; index++) {
		storage[index] = another.storage[index];
	}
	return *this;
}
list::~list(){
	clear();
}
 // Capacity
bool list::empty(void) const {
	if (_size == 0) return true;
	else return false;
}
size_type list::size(void) const{
	return _size;
}
// output
// list: [1,2,3,4,5]
// output: 1->2->3->4->5->NULL
std::string list::toString(void) const{
	string str;
	if (head != nullpointer){
		char num[5];
		pointer current = head;
		while (current != empty_head && current != nullpointer) {
			sprintf(num,"%d",storage[current].data);
			current = storage[current].next;
			str += num;
			str += "->";
		}
	}
	str += "NULL";
	return str;
}
void list::insert(int position, const int& data){
	if (position > _size || position < 0 || _size > MAX_STORAGE) return;
	else {
		if (position == 0){
			pointer poi = empty_head;
			empty_head = storage[empty_head].next;
			storage[poi].data = data;
			storage[poi].next = head;
			head = poi;
		}
		else if (position <= _size){
			pointer poi = empty_head;
			empty_head = storage[empty_head].next;
			storage[poi].data = data;

			pointer current = head;
			pointer prev = head;
			for (int index = 0; index < position; index++) {
				prev = current;
				current = storage[current].next;
			}
			storage[prev].next = poi;
			storage[poi].next = current;
		}
		_size++;
	}
}
void list::erase(int position){
	if ( position > _size) return;
	else {
		if (position == 0){
			pointer poi = head;
			head = storage[head].next;
			storage[poi].data = 0;
			storage[poi].next = empty_head;
			empty_head = poi;
		}
		else if (position <= _size){
			pointer current = head;
			pointer prev = head;
			for (int index = 0; index < position; index++) {
				prev = current;
				current = storage[current].next;
			}
			storage[prev].next = storage[current].next;
			storage[current].data = 0;
			storage[current].next = empty_head;
			empty_head = current;
		}	
		_size--;
	}
}
void list::clear(void){
	for (int index = 0; index < MAX_STORAGE; index++) {
		storage[index].data = 0;
		storage[index].next = nullpointer;
	}
	head = nullpointer;
	empty_head = nullpointer;
	_size = 0;
}
list& list::sort(void){
	if (_size != 0){
		int index1, index2;
		int num;
		pointer current;
		pointer father;
		for (index1 = 0; index1 < _size-1; index1++) {
			father = head;
			current = head;
			for (index2 = 0; index2 < index1; index2++) {
				father = storage[father].next;
				current = storage[current].next;
			}
			for (; index2 < _size-1; index2++){
				current = storage[current].next;
				if (storage[father].data > storage[current].data) {
					num = storage[father].data;
					storage[father].data = storage[current].data;
					storage[current].data = num;
				}
			}
		}
	}
	return *this;
}