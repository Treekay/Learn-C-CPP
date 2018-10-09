#include "SimpleList.hpp"
#include <iostream>
#include <cstdio>
using namespace std;
list::list(){
	head = NULL;
	_size = 0;
}
list::list(const list& point){
	head = new node(point.head->data);
	node* p1 = point.head;
	node* p2 = head;
	_size = point._size;
	while (p1->next != NULL) {
		 p2->next = new node(p1->next->data);
		 p2 = p2->next;
		 p1 = p1->next;
	}
}
list& list::operator=(const list& point){
	clear();
	_size = 0;
	head = new node(point.head->data);
	node* p1 = point.head;
	node* p2 = head;
	_size = point._size;
	while (p1->next != NULL) {
		 p2->next = new node(p1->next->data);
		 p2 = p2->next;
		 p1 = p1->next;
	}
	return *this;
}
list::~list(){
	clear();
}
bool list::empty(void) const{
	if (head == NULL) return true;
	else return false;
}
int list::size(void) const{
	return _size;
}
void list::insert(int position, const int& data){
	if ( position > _size) return;
	else {
		if (position == 0) {
			node* poi;
			poi = new node(data,head);
			head = poi;
		}
		else if (position > 0 && position < _size){
			int index;
			node* father;
			node* current;
			current = head;
			for (index = 0; index < position; index++) {
				father = current;
				current = current->next;
			}
			node* poi;
			poi = new node (data,current);
			father->next = poi;
		}
		else if (position == _size){
			int index;
			node* current;
			node* father;
			current = head;
			for (index = 0; index < position; index++) {
				father = current;
				current = current->next;
			}
			node *poi;
			poi  = new node (data);
			father->next = poi;
		}
		_size++;
	}
}
void list::erase(int position){
	if ( position > _size) return;
	else {
		if (position == 0) {
			node* poi;
			poi = head;
			head = head->next;
			delete poi;
		}
		else if (position > 0 && position <= _size){
			node * father;
			node* current;
			current = head;
			int index;
			for (index = 0; index < position; index++) {
				father = current;
				current = current->next;
			}
			if (current->next != NULL) {
				node* son = current->next;
				father->next = son;
			}
			delete current;
		}
		_size--;
	}
}
list& list::sort(void){
	int index, index1;
	int num;
	node* current;
	node* father;
	for (index = 0; index < _size-1;index++) {
		father = head;
		current = head;
		for (index1 = 0;index1 < index; index1++) {
			father = father->next;
			current = current->next;
		}
		for (; index1 < _size-1; index1++) {
			current = current->next;
			if (father->data > current->data) {
				num = father->data;
				father->data = current->data;
				current->data = num;
			}
		}
	}
	return *this;
}
std::string list::toString(void) const{
	std::string str;
	int index;
	node* poi;
	char c[5];
	poi = head;
	for (index = 0; index < _size;index++) {
			sprintf(c,"%d",poi->data);
			str += c;
 str += "->";
		poi = poi->next;
	}
	str += "NULL";
	return str;
}