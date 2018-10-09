 #include "RHTree.hpp"

RHTree::RHTree(){
	root = NULL;
}
RHTree::~RHTree(){
	MemoryDelete(root);
}
void RHTree::MemoryDelete(node* poi){
	if (poi != NULL){
		MemoryDelete(poi->left);
		MemoryDelete(poi->right);
		delete poi;
	}
}
void RHTree::insert(int value){
	if (root == NULL) {
		root = new node(value);
		return;
	}
	node* poi = root;
	while (1){
		if (value <= poi->ele) {
		    if (poi->left != 0) {
		    	poi = poi->left;
		    	continue;
		    }
		    else { 
		      poi->left = new node(value);
		      break;
		    }
	  	}
	 	 else if (value > poi->ele) {
		    if (poi->right != 0) {
		    	poi = poi->right;
		    	continue;
		    }
		    else {
		      poi->right = new node(value);
		      break;
		    }
	 	}
	 }
}
node* RHTree::getRoot()const{
	return root;
}
void RHTree::inOrder(node* poi)const{
	if (poi != NULL){
		inOrder(poi->left);
		cout << " " << poi->ele ;
		inOrder(poi->right);
	}
}
void RHTree::preOrder(node* poi)const{
	if (poi != NULL){
		cout << " " << poi->ele ;
		preOrder(poi->left);
		preOrder(poi->right);
	}
}
void RHTree::postOrder(node* poi)const{
	if (poi != NULL){
		postOrder(poi->left);
		postOrder(poi->right);
		cout << " " << poi->ele ;
	}
}