#include "LinkedList.hpp"

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    _size = 0;
}
LinkedList::~LinkedList(){
    clear();
}
void LinkedList::add(E e){
    if (head == NULL) {
        head = new node(e);
        tail = head;
        _size++;
    } 
    else {
        node* poi = new node(e);
        tail->next = poi;
        poi->prev = tail;
        tail = poi;
        _size++;
    }
}
void LinkedList::remove(E e){
    node* p = head;
    node* temp = NULL;
    while (p != NULL) {
        if (p->data == e) {
            if (_size == 1) {
                delete head;
                tail = NULL;
                head = NULL;
                p = NULL;
                _size--;
                return;
            }
            else if (p == head) {
                temp = p;
                p = p->next;
                p->prev = NULL;
                head = p;
                delete temp;
            }
            else if (p == tail) {
                tail = p->prev;
                p->prev->next = NULL;
                delete p;
                p = NULL;
            } 
            else {
                p->next->prev = p->prev;
                p->prev->next = p->next;
                temp = p->next;
                delete p;
                p = temp;
            }
            _size--;
    	} 
	    else p = p->next;
    }
}
void LinkedList::clear(){
    node* p = head;
    node* temp = NULL;
    if (p != NULL) {
        while (p->next != NULL) {
            temp = p;
            p = p->next;
            delete temp;
        }
        delete p;
    }
    head = NULL;
    tail = NULL;
    _size = 0;
}
bool LinkedList::contain(E e){
    node* poi = head;
	while (poi != NULL){
		if (poi->data == e) return true;
		poi = poi->next;
	}
	return false;
}
bool LinkedList::isEmpty(){
    return _size == 0;
}
E& LinkedList::operator[](int index){
    return get(index);
}
E& LinkedList::get(int index){
    node* poi = head;
	while( index--) {
		poi = poi->next;
	}
	return poi->data;
}
int LinkedList::indexOf(E element){
    node* current = head;
    for (int index = 0; index < _size; index++){
        if (current->data == element) return index;
        current = current->next;
    }
    return -1;
}
int LinkedList::size(){
    return _size;
}