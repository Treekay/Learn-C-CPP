#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

void BinaryTree::MemoryDelete(node* p){// 内存处理的辅助函数
	if (p != NULL){
		BinaryTree::MemoryDelete(p->left);
		BinaryTree::MemoryDelete(p->right);
		delete p;
	}
}
void BinaryTree::BuildTree(const node* Source_Root, node* &Target_Root){ // 拷贝构造函数的辅助函数
	if(Source_Root != NULL){
      Target_Root = new node(Source_Root->ele);
      BuildTree(Source_Root->left,Target_Root->left);
      BuildTree(Source_Root->right,Target_Root->right);
    }
}
void BinaryTree::BuildTree(const int* arr,int len, node* &root){ // 数组构建树的辅助函数
	node* current = root;
	for (int index = 0; index < len; index++){
		current = root;
		while (current != NULL){
			if (arr[index] > current->ele){
				if (current->right != NULL) current = current->right;
				else {
					current->right = new node(arr[index]);
					break;
				}
			}
			else if (arr[index] < current->ele){
				if (current->left != NULL) current = current->left;
				else {
					current->left = new node(arr[index]);
					break;
				}
			}
			else break;
		}
	}
}
void BinaryTree::preorder(const node* p){   // 输出的辅助函数
	if (p != NULL){
		cout << p->ele << " ";
		BinaryTree::preorder(p->left);
		BinaryTree::preorder(p->right);
	}
}

BinaryTree::BinaryTree(){
	root = NULL;
}
BinaryTree::BinaryTree(const BinaryTree& Source_Root){
	if (Source_Root.root == NULL) root = NULL;
	else BinaryTree::BuildTree(Source_Root.root , root);
}
BinaryTree::BinaryTree(const int* arr, int len){
	root = new node(arr[0]);
	BinaryTree::BuildTree( arr, len, root);
}
void BinaryTree::ResetTree(const int* arr, int len) {// 清空当前树并重置
	BinaryTree::clear();
	root = new node(arr[0]);
	BinaryTree::BuildTree(arr, len, root);
}
BinaryTree::~BinaryTree(){
	if (root != NULL) BinaryTree::MemoryDelete(root);
	root = NULL;
}
void BinaryTree::clear(){  // 清空
	BinaryTree::MemoryDelete(root);
	root = NULL;
}
void BinaryTree::insert(int ele){ // 按值插入
	if (root == NULL) root = new node(ele);
	else {
		node* current = root;
		while (current != NULL){
			if (ele > current->ele){
				if (current->right != NULL) current = current->right;
				else {
					current->right = new node(ele);
					break;
				}
			}
			else if (ele < current->ele){
				if (current->left != NULL) current = current->left;
				else {
					current->left = new node(ele);
					break;
				}
			}
			else break;
		}
	}
}
void BinaryTree::Delete(int ele){ // 暗值删除
	node* current = root;
	node* poi;
	while (current != NULL){
		if (ele > current->ele){
			if (current->right != NULL) {
				poi = current;
				current = current->right;
			}
			else break;
		}
		else if (ele < current->ele){
			if (current->left != NULL) {
				poi = current;
				current = current->left;
			}
			else break;
		}
		else if (ele == current->ele){
			if (current == root){
				if (current->left == NULL ){
					root = root->right;
				}
				else if (current->left != NULL){
					if (current->left->right == NULL){
						root = root->left;
						root->right = current->right;
					}
					else {
						node* leftson = current->left;
						node* maxright = current;
						while (leftson->right != NULL){
							maxright = leftson;
							leftson = leftson->right;
						}
						root = leftson;
						leftson->right = current->right;
						maxright->right = leftson->left;
						leftson->left = current->left;
					}
				}
			}
			else if (current->left == NULL){
				if (poi->ele > current->ele) poi->left = current->right;
				else if (poi->ele < current->ele) poi->right = current->right;
			}
			else if (current->left != NULL){
				if (current->left->right == NULL){
					if (poi->ele > current->ele) poi->left = current->left;
					else if (poi->ele < current->ele) poi->right = current->left;
					current->left->right = current->right;
				}
				else if (current->left->right != NULL){
					node* leftson = current->left;
					node* maxright = current;
					while (leftson->right != NULL){
						maxright = leftson;
						leftson = leftson->right;
					}
					if (poi->ele > current->ele) poi->left = leftson;
					else if(poi->ele < current->ele) poi->right = leftson;
					leftson->right = current->right;
					maxright->right = leftson->left;
					leftson->left = current->left;
				}
			}
			delete current;
			current = NULL;
			break;
		}
		else break;
	}
}
void BinaryTree::print(){
	BinaryTree::preorder(root);
	cout << endl;
}