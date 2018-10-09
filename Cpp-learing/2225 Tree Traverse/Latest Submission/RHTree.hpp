#include <iostream>
using namespace std;
struct node {
  int ele;
  node* left;
  node* right;
  node(int num):left(0), right(0){
    ele = num;
  }
};

class RHTree {
private:
	node* root;
public:
	RHTree();
	~RHTree();
	void MemoryDelete(node*);
	void insert(int num);
	node* getRoot()const;
	void inOrder(node* )const;
	void preOrder(node* )const;
	void postOrder(node* )const;
};