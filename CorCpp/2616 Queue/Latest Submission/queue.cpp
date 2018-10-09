#include "queue.hpp"

queue::queue(){
    max_size = MAX_SIZE + 1;
    head = rear = 0;
    storage = new E[MAX_SIZE + 1];
}
queue::~queue(){
    delete [] storage;
}
void queue::push(E num){
    if (!isFull()){
        storage[rear] = num;
        rear = (rear + 1) % max_size;
    }
}
void queue::pop(){
    if(!isEmpty()){
        storage[head] = 0;
        head = (head + 1) % max_size;
    }
}
E queue::front(){
    if (isEmpty()) return 0;
    else return storage[head];
}
E queue::back(){
    if (isEmpty()) return 0;
    else return storage[(rear + max_size - 1) % max_size];
}
bool queue::isFull(){
    return (rear + 1) % max_size == head;
}
bool queue::isEmpty(){
    return head == rear;
}
void queue::clear(){
    head = rear = 0;
}