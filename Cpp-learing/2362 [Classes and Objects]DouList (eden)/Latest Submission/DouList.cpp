#include "DouList.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int _error_sign = 0;  // for illegal front()/back()

 DouList::DouList(){
 	m_head = NULL;
 	m_tail = NULL;
 }
 DouList::DouList(const DouList &src){
 	if (src.m_head == NULL){
 		m_head = src.m_head;
 		m_tail = src.m_tail;
 	}
 	else {
		m_head = new DouListNode(src.m_head->elem);
		DouListNode * p1;
		DouListNode * p2;
		p1 = src.m_head;
		p2 = m_head;
		while (p1->next != NULL) {
			p2->next = new DouListNode(p1->next->elem);
			p2->next->prev = p2;
			p2 = p2->next;
			p1 = p1->next;
		}
		m_tail = p2;
	}
 }
 DouList::~DouList(){
 	clear();
 }
void  DouList::clear(){
	if (m_head != NULL) {
	    DouListNode * p = m_head;
	    while (p != NULL) {
	      m_head = m_head->next;
	      delete p;
	      p = m_head;
	      if (m_head != NULL) m_head->prev = NULL;
   		}
 	}
 	m_head = NULL;
  	m_tail = NULL;
}
bool  DouList::empty() const{
	if (m_head == NULL) return true;
	else return false;
}
std::string  DouList::to_str() const{
	string str;
	DouListNode * poi;
	stringstream ss;
	string num;
	poi = m_head;
	str += "[";
	while (poi != NULL) {
	  	ss.clear();
	    ss << poi->elem;
	    ss >> num;
	    str += num;
	    if (poi->next != NULL) str += ", ";
	    poi = poi->next;
	}
	str += "]";
	return str;
}
int  DouList::front() const{
	int _error_sign;
	if (empty()) return _error_sign;
	else return m_head->elem;
}
int  DouList::back() const{
	int _error_sign;
	if (empty()) return _error_sign;
	else return m_tail->elem;
}
void  DouList::push_front(const int &e){
	if (m_head == NULL){
		m_head = new DouListNode(e);
		m_tail = m_head;
	}
	else {
		m_head->prev = new DouListNode(e);
		m_head->prev->next = m_head;
     	m_head = m_head->prev;
	}
}
void  DouList::push_back(const int &e){
	if (m_head == NULL){
		m_head = new DouListNode(e);
		m_tail = m_head;
	}
	else {
		m_tail->next = new DouListNode(e);
		m_tail->next->prev = m_tail;
     	m_tail = m_tail->next;
	}
}
void  DouList::pop_front(){
	if (m_head == NULL) return;
	else {
		DouListNode * dis = m_head;
		m_head = m_head->next;
		delete dis;
	}
}
void  DouList::pop_back(){
	if (m_tail == NULL) return;
	else {
		DouListNode *dis = m_tail;
		m_tail = m_tail->prev;
		delete dis;
		m_tail->next = NULL;
	}
}
DouList&  DouList::operator=(const DouList &other){
	DouList save(other);
	clear();
	if (save.m_head == NULL) {
		m_head = NULL;
		m_tail = NULL;
	}
	else {
		m_head = new DouListNode(save.m_head->elem);
		DouListNode *p1;
		DouListNode *p2; 
		p1 = save.m_head;
		p2 = m_head;
		while (p1->next != NULL) {
			p2->next = new DouListNode(p1->next->elem);
			p2->next->prev = p2;
			p2 = p2->next;
			p1 = p1->next;
		}
		m_tail = p2;
	}
	return *this;
}
std::ostream& operator<<(std::ostream &out,
       const DouList &list){
	out << list.to_str();
	return out;
}
// non-meaning static value
