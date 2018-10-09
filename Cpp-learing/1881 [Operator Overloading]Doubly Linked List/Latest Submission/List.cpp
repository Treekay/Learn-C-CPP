#include "List.hpp"
#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
list::list(){
  head = NULL;
  tail = NULL;
  _size = 0;
}
// construct a list from an exist array
list::list(const data_type num[], int length){
	if (length == 0) {
		head = NULL;
		tail = NULL;
		_size = 0;
	}
	else {
		head = new node (num[0]);
		listPointer current;
		current = head;
		_size = length;
		for (int index = 1; index  <length; index++) {
			current->next = new node (num[index]);
			current->next->prev = current;
			current = current->next;
		}
		tail = current;
	}
}
list::list(const list& other){
	if (other.head == NULL) {
		head = NULL;
		tail = NULL;
		_size = 0;
	}
	else {
		head = new node(other.head->data);
		listPointer p1;
		listPointer p2;
		p1 = other.head;
		p2 = head;
		_size = other._size;
		while (p1->next != NULL) {
			p2->next = new node(p1->next->data);
			p2->next->prev = p2;
			p2 = p2->next;
			p1 = p1->next;
		}
		tail = p2;
	}
}
list& list::operator=(const list& other){
	clear();
	if (other.head == NULL) {
		head = NULL;
		tail = NULL;
		_size = 0;
	}
	else {
		head = new node(other.head->data);
		listPointer p1;
		listPointer p2; 
		p1 = other.head;
		p2 = head;
		_size = other._size;
		while (p1->next != NULL) {
			p2->next = new node(p1->next->data);
			p2->next->prev = p2;
			p2 = p2->next;
			p1 = p1->next;
		}
		tail = p2;
	}
	return *this;
}
list::~list(){
  clear();
}

// Capacity
bool list::empty(void) const{
  if (_size == 0) return true;
  else return false;
}
list::size_type list::size(void) const{
  return _size;
}

// Element access
list::data_type& list::front(void) const{
  return head->data;
}
list::data_type& list::back(void) const{
  return tail->data;
}

std::string list::toString(void) const{
  string str;
  listPointer poi;
  stringstream ss;
  string num;
  poi = head;
  str += "NULL";
  if (_size != 0) str += "<-";
  while (poi != NULL) {
  	ss.clear();
    ss << poi->data;
    ss >> num;
    str += num;
    if (poi->next != NULL) str += "<->";
    else str += "->";
    poi = poi->next;
  }
  if (_size != 0) str += "NULL";
  return str;
}

// Modifiers
void list::assign(const list& other){
	clear();
	if (other.head == NULL) {
		head = NULL;
		tail = NULL;
		_size = 0;
	}
	else {
		head = new node(other.head->data);
		listPointer p1;
		listPointer p2;
		p1 = other.head;
		p2 = head;
		_size = other._size;
		while (p1->next != NULL) {
			p2->next = new node(p1->next->data);
			p2->next->prev = p2;
			p2 = p2->next;
			p1 = p1->next;
		}
		tail = p2;
	}
}
void list::assign(const list::data_type num[], int length){
	clear();
	if (length == 0) {
		head = NULL;
		tail = NULL;
		_size = 0;
	}
	else {
		head = new node (num[0]);
		listPointer current;
		current = head;
		_size = length;
		for (int index = 1; index  <length; index++) {
			current->next = new node (num[index]);
			current->next->prev = current;
			current = current->next;
		}
		tail = current;
	}
}
void list::push_front(const list::data_type& value){
	if (head == NULL){
		head = new node(value);
		tail = head;
		_size++;
	}
	else {
		head->prev = new node(value);
		head->prev->next = head;
     	head = head->prev;
		_size++;
	}
}
void list::push_back(const list::data_type& value){
	if (head == NULL){
		head = new node(value);
		tail = head;
		_size++;
	}
	else {
		tail->next= new node(value);
		tail->next->prev = tail;
		tail = tail->next;
		_size++;
	}
}
void list::pop_front(void){
	if (head == NULL) return;
	else {
		listPointer dis = head;
		head = head->next;
		delete dis;
		_size--;
	}
}
void list::pop_back(void){
	if (tail == NULL) return;
	else {
		listPointer dis = tail;
		tail = tail->prev;
		delete dis;
		tail->next = NULL;
		_size--;
	}
}
void list::insert(int position, const list::data_type& data){
	if (position > _size || position < 0) return;
	if (position == 0) push_front(data);
	else if (position == _size) push_back(data);
	else if (position > 0 && position < _size){
		listPointer add = new node(data);
		listPointer current;
		current = head;
		for (int index = 0; index < position; index++) {
			current = current->next;
		}
		current->prev->next = add;
		add->prev = current->prev;
		add->next = current;
		current->prev = add;
		_size++;
	}
}
void list::erase(int position){
  	if (position >= _size || position < 0) return;
	else {
		if (position == 0) pop_front();	
		else if (position > 0 && position < _size-1){
			listPointer current;
			current = head;
			for (int index = 0; index < position; index++){
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			_size--;
		}
		else if (position == _size-1) pop_back();
	}
}
void list::clear(void){
  if (head != NULL) {
    listPointer p = head;
    while (p != NULL) {
      head = head->next;
      delete p;
      p = head;
      if (head != NULL) head->prev = NULL;
    }
  }
  head = NULL;
  tail = NULL;
  _size = 0;
}

// Operations
// split this list into to lists at the given position
void list::split(int position, list* des1, list* dest2){
	des1->clear();
	dest2->clear();
	if (head != NULL){
	  int index = 0;
	  if (position != 0) des1->head = new node (head->data);
	  else des1->head = NULL;
	  des1->_size = position;
	  dest2->_size = _size - position;
	  listPointer p1;
	  listPointer poi;
	  p1 = des1->head;
	  poi = head;
	  for (index = 0; index < position -1; index++) {
	    p1->next = new node (poi->next->data);
	    p1->next->prev = p1;
	    poi = poi->next;
	    p1 = p1->next;
	  }
	  des1->tail = p1;

	  if (position == 0) dest2->head = new node(poi->data);
	  else if (position != _size) {
	  	dest2->head = new node(poi->next->data);
	  	poi = poi->next;
	  }
	  else dest2->head = NULL;
	  listPointer p2;
	  p2 = dest2->head;
	  while (poi->next != NULL) {
   		p2->next = new node(poi->next->data);
   		p2->next->prev = p2;
   		poi = poi->next;
   		p2 = p2->next;
	   }
	  dest2->tail = p2;
	}
	else return;
	/*if (head == NULL) {
		des1->head = NULL;
		des1->tail = NULL;
		des1->_size = 0;
		dest2->head = NULL;
		dest2->tail = NULL;
		dest2->_size= 0;
	}
	else {
		if (position == 0){
			des1->head = NULL;
			des1->tail = NULL;
			des1->_size = 0;

			dest2->assign(*this);
		}
		else if (position > 0 && position < _size){
			des1->head = new node(head->data);
			listPointer current;
			current = head;
			listPointer p1;
			p1 = des1->head;
			for(int index = 1; index < position; index++) {
				p1->next = new node(current->next->data);
				p1->next->prev = p1;
				p1 = p1->next;
				current = current->next;
			}
			des1->tail = p1;
			des1->_size = position;

			dest2->head = new node(current->data);
			listPointer p2;
			p2 = dest2->head;
			for (int index = 1; index < _size - position; index++){
				p2->next = new node(current->next->data);
				p2->next->prev = p2;
				p2 = p2->next;
				current = current->next;
			}
			dest2->tail = p2;
			dest2->_size = _size - position;
		}
		else if (position == _size){
			dest2->head = NULL;
			dest2->tail = NULL;
			dest2->_size = 0;

			des1->assign(*this);
		}
	}*/
}
// merge two list to this list from src1 and src2
list& list::merge(const list& src1, const list& src2){
	list s1 = src1;
	list s2 = src2;
	clear();
	if (s1.head == NULL && s2.head != NULL) {
		*this = s2;
	} 
	else if (s1.head != NULL && s2.head == NULL){
		*this = s1;
	}
	else {
		*this = s1;
		*this += s2;
	}
	s1.clear();
	s2.clear();
	return *this;
}
// remove the elements who satisfy the condition
list& list::remove_if(bool (*condition)(listPointer)){
	listPointer current;
	listPointer poi;
	while (head != NULL) {
		if (condition(head)){
			poi = head;
			head = head->next;
			delete poi;
			_size--;
		}
		else break;
	}
	if (head != NULL){
		current = head;
		while (current != NULL){
			if (condition(current)){
				current->prev->next = current->next;
				if (current->next != NULL) {
					current->next->prev = current->prev;
				}
				poi = current;
				current = current->next;
				delete poi;
				_size--;
			}
			else current = current->next;
		}
	}
	else tail = NULL;
	return *this;
}
// remove duplicate elements
list& list::unique(void){
	if (head != NULL){
		listPointer p1 = head;
		while (p1->next != NULL){
			listPointer p2 = p1->next;
			while (p2->next != NULL){
				if (p1->data == p2->data) {
		          listPointer poi = p2;
		          p2->prev->next = p2->next;
		          p2->next->prev = p2->prev;
		          p2 = p2->next;
		          delete poi;
		          _size--;
       			}
      		    else p2 = p2->next;
     		}
	      	if (p1->data == p2->data) {
		        p2->prev->next = NULL;
		        tail = p2->prev;
		        delete p2;
		        _size--;
	    	 }
      		if (p1->next != NULL) p1 = p1->next;
     		else break;	
		}
	}
	return *this;
}
// reverse the list
list& list::reverse(void){
	return *this;
}
// operators
list::data_type& list::operator[](int index){
	return at(index)->data;
}
list& list::operator +=(const list& other){
	if (head != NULL && other.head != NULL){
	  _size += other._size;
	  listPointer p1 = other.head;
	  listPointer p2 = tail;
	  while (p1 != NULL){
	    p2-> next = new node (p1->data);
	    p2->next->prev = p2;
	    p2 = p2 -> next;
	    p1 = p1 -> next;
	  }
	  tail = p2;
	}
	else if (head == NULL && other.head != NULL){
		head = new node (other.head->data);
	  listPointer p1 = other.head;
	  listPointer p2 = head;
	  _size = other._size;
	  while (p1 -> next != NULL){
	    p2-> next = new node (p1->next->data);
	    p2->next->prev = p2;
	    p2 = p2 -> next;
	    p1 = p1 -> next;
	  }
 	 tail = p2;
	}
  return *this;
}
std::ostream& operator<< (std::ostream& os,const list &li) {
  os << li.toString();
  return os;
}