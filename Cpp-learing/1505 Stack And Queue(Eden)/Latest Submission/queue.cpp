#include "queue.hpp"

void queue::push(int num){
  if (isFull()) return;
  storage[rear] = num;
  rear = (rear + 1) % max_size;
}
void queue::pop(void){
  if (isEmpty()) return;
  head = (head + 1) % max_size;
}
int queue::front(void){
  if (isEmpty()) return 0;
  return storage[head];
}
int queue::back(void){
  if (isEmpty()) return 0;
  return storage[(rear -1 + max_size) % max_size];
}
bool queue::isFull(void){
  return ((rear + 1) % max_size) == head;
}
bool queue::isEmpty(void){
  return head == rear;
}
void queue::clear(void){
  rear = head;
}