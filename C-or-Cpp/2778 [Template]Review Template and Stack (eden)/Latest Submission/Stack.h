 #ifndef STACK_H_
#define STACK_H_

#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class Stack {
  public:
    Stack(){ // constructor.
        count = 0;
    }
    void push(const T& data){ // push operation.
        if (!q1.empty()|| q1.empty() && q2.empty()) 
            q1.push(data);
        else if (!q2.empty())
            q2.push(data);
        count++;
    }
    T pop(){ // return the value in the top and pop it out of the stack.
        if (!empty()){
            if (q1.empty()){
                int times = q2.size();
                T num = q2.back();
                for (int index = 0; index < times-1; index++){
                    q1.push(q2.front());
                    q2.pop();
                }
                q2.pop();
                count--;
                return num;
            }
            else if (q2.empty()){
                int times = q1.size();
                T num = q1.back();
                for (int index = 0; index < times-1; index++){
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.pop();
                count--;
                return num;
            }
        }
        else return 0; 
    }
    T top(){ // return the value in top.
        if (q1.empty())
            return q2.back();
        else if (q2.empty())
            return q1.back();
    }
    int size() const{  // return size of the stack.
        return count;
    }
    bool empty(){ // check whether is empty.
        if (count == 0) return true;
        else return false;
    }
  private:
    queue<T> q1; // two queues.
    queue<T> q2;
    int count; // the number of elements.
};

template <typename T>
void print(T stack){
    T other;
    if (!stack.empty()){
        while(!stack.empty()){
            cout << stack.top() << ' ';
            other.push(stack.top());
            stack.pop();
        }
        while(!other.empty()){
            stack.push(other.top());
            other.pop();
        }
    }
    cout << endl;
}

#endif