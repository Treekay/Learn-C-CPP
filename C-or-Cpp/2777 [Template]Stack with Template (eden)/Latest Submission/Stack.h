 #ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;
class Job;

 template<class T> 
class Stack {  
    public:  
        Stack(){
            node_num = 0;
            top_node = NULL;
        }

        Stack(const Stack &stack){
            if (stack.top_node != NULL){
                top_node = new Node(stack.top_node->element);
                Node* poi = top_node;
                Node* current = stack.top_node;
                node_num = stack.node_num;
                while(current->next != NULL){
                    poi->next = new Node(current->next->element);
                    poi = poi->next;
                    current = current->next;
                }
            }
            else{
                node_num = 0;
                top_node = NULL;
            }
        }

        ~Stack(){
            clear();
        }

        bool empty(){
            if (node_num == 0) return true;
            else return false;
        }

        size_t size() const{
            return node_num;
        }

        T top() const{
            if (top_node != NULL) return top_node->element;
        }

        void push(T element){
            Node* new_node;
            new_node = new Node(element);
            new_node->next = top_node;
            top_node = new_node;
            node_num++;
        }

        void pop(){
            if (!empty()) {
                Node* poi = top_node;
                top_node = top_node->next;
                delete poi;
                node_num--;
            }
        }

        void swap(Stack& stack){
            Stack save1(stack);
            Stack save2(*this);
            stack.clear();
            clear();
            if (save1.top_node != NULL){
                top_node = new Node(save1.top_node->element);
                Node* poi1 = top_node;
                Node* current1 = save1.top_node;
                node_num = save1.node_num;
                while(current1->next != NULL){
                    poi1->next = new Node(current1->next->element);
                    poi1 = poi1->next;
                    current1 = current1->next;
                }
            }
            if (save2.top_node != NULL){
                stack.top_node = new Node(save2.top_node->element);
                Node* poi2 = stack.top_node;
                Node* current2 = save2.top_node;
                stack.node_num = save2.node_num;
                while(current2->next != NULL){
                    poi2->next = new Node(current2->next->element);
                    poi2 = poi2->next;
                    current2 = current2->next;
                }
            }
        }

        void reverse(){/*reverse the elements' order in the stack*/
            Stack stack(*this);
            clear();
            while(!stack.empty()){
                push(stack.top());
                stack.pop();
            }
        }

        void clear(){
            if (!empty()){
              Node* poi = top_node;
              while (poi != NULL){
                top_node = top_node->next;
                delete poi;
                poi = top_node;
              	}
              node_num = 0;
              top_node = NULL;
            }
        }

    private:  
        struct Node {  
            T element;  
            Node* next;  
            Node(T ele, Node *n = NULL) {  
                element = ele;  
                next = n;  
            }  
        };  
        Node *top_node;  
        size_t node_num;  
};

#endif