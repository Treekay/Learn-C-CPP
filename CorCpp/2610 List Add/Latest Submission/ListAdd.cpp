#include <iostream>
#include <cmath>
#include "ListAdd.hpp"
using namespace std;
List::List(){
 head = NULL;
 _size = 0;
}
      List::List(const List& other) {
       if (other._size ==  0) {
          head = NULL;
          _size = 0;
          return;
       }
        _size = other._size;
        head = new struct node(other.head->val);
        struct node *p1 = head;
        struct node *p2 = other.head;
        while(p2->next != NULL) {
         p1->next = new struct node(p2->next->val);
         p1 = p1->next;
         p2 = p2->next;
        }
        p1->next = NULL;
      }

      List::List(const string & num) {
       _size = num.length();
       head = new struct node(num[_size - 1] - 48);
       struct node *p = head;
       for (int i = _size - 2; i >= 0; --i) {
          p->next = new struct node(num[i]- 48);
          p = p->next;
       }
        p->next = NULL;
      }
      void List::clear() {
       struct node *p1 = head;
        struct node *p2 = head;
        while (p1 != NULL){
           p1 = p1->next;
           delete p2;
           p2 = p1;
        }
        _size = 0;
        head = NULL;
      }
      void List::push_front(int val) {
        struct node *p = new struct node(val);
        p->next = head;
        head = p;
        ++_size;
      }  
      List List::operator+(const List& other) {
       if(head == NULL)
        return List(other);
       if (other.head == NULL)
        return *this;
        List c = *this;
        struct node *p1 = c.head;
        struct node *p2 = other.head;
        while (p1->next != NULL && p2->next != NULL) {
          p1->val += p2->val;
          p1 = p1->next;
          p2 = p2->next;
        }
        p1->val += p2->val;
        while (p2->next != NULL) {
         p1->next = new struct node(p2->next->val);
         p1 = p1->next;
         p2 = p2->next;
         ++c._size;
        }
        while (p1->next != NULL)
          p1 = p1->next;
        p1->next = NULL;
        p1 = c.head;
        while (p1->next != NULL) {
          if (p1->val > 9) {
            ++p1->next->val;
            p1->val -= 10;
          }
          p1 = p1->next;
        }
        if (p1->val > 9) {
          p1->next = new struct node(1);
          p1->next->next = NULL;
          p1->val -= 10;
          ++c._size;
        }
        return c;
      }   

      List& List::operator=(const List& other) {
       if (head == other.head)
        return *this;
        clear();
        if (other._size ==  0)
          return *this;
        _size = other._size;
        head = new struct node(other.head->val);
        struct node *p1 = head;
        struct node *p2 = other.head;
        while(p2->next != NULL) {
         p1->next = new struct node(p2->next->val);
         p1 = p1->next;
         p2 = p2->next;
        }
        p1->next = NULL;
        return *this;
      }   
      int List::size() const {
       return _size;
      }
      List::~List() {
       clear();
      }

      ostream& operator<<(ostream & os, const List & other) {
       List::node * p = other.head;
       int num[other._size];
       int i = 0;
       while (p != NULL) {
         num[i++] = p->val;
         p = p->next;
       } 
         for(int i = other._size - 1; i >= 0; --i)
            os << num[i];
       return os;
      }