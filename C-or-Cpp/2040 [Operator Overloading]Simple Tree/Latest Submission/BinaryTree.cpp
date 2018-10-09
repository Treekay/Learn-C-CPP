#include <iostream>
#include "BinaryTree.hpp"
using namespace std;
      void BinaryTree::MemoryDelete(node* p) {
      if(p != NULL){
        MemoryDelete(p->left);
        MemoryDelete(p->right);
        delete p;
      }
    } 
  void BinaryTree::BuildTree(const node* Source_Root, node* &Target_Root){
    if(Source_Root != NULL){
      Target_Root = new node(Source_Root->ele);
      BuildTree(Source_Root->left,Target_Root->left);
      BuildTree(Source_Root->right,Target_Root->right);
    }
  } 
    
    void BinaryTree::BuildTree(const int* arr,int i, node* &p) { 
      if (arr[i] > p->ele) {
        if (p->right != NULL)
          BuildTree(arr, i, p->right);
        else
          p->right = new node(arr[i]);
      }
      else if (arr[i] < p->ele) {
        if (p->left != NULL)
          BuildTree(arr, i, p->left);
        else
          p->left = new node(arr[i]);
      }
        }
      
    void BinaryTree::preorder(const node* p) { 
      if (p != NULL){
        cout<<p->ele<<' ';
        preorder(p->left);
        preorder(p->right);
    }
    }

    BinaryTree::BinaryTree(){
       root = NULL;
  }
    BinaryTree::BinaryTree(const BinaryTree& a){
      if(a.root ==NULL)
        root = NULL;
      else
        BuildTree(a.root, root);
  }


    BinaryTree::BinaryTree(const int* arr, int len) {
      root = new node(arr[0]);
      for (int i = 1; i < len; ++i)
        BuildTree(arr, i, root);
    }

    void BinaryTree::ResetTree(const int* arr, int len) {  
      this->clear();
      root = new node(arr[0]);
      for (int i = 1; i < len; ++i)
        BuildTree(arr, i, root);
    } 

    BinaryTree::~BinaryTree() {
      if(root != NULL)
        MemoryDelete(root);
      root = NULL;
    }
    
    void BinaryTree::clear() {  
      MemoryDelete(root);
      root = NULL;
    } 

    void BinaryTree::insert(int k) {    
      node *p = root;
      while(p != NULL) {
        if (k > p->ele) {
          if (p->right != NULL)
            p = p->right;
          else {
            p->right = new node(k);
            break;
          }
        }
        else if (k < p->ele) {
          if (p->left != NULL)
            p = p->left;
          else {
            p->left = new node(k);
            break;
          }
        }
        if (k == p->ele)
          break;
      }
       if(root == NULL)
        root = new node(k);
    }

    void BinaryTree::Delete(int k) { 
      node *p1 = root;
      node *p2;
      while(p1 != NULL) {
        if (k > p1->ele) {
          if (p1->right != NULL) {
            p2 = p1;
            p1 = p1->right;
          }
          else
            break;
        }
        else if (k < p1->ele) {
          if (p1->left != NULL) {
            p2 = p1;
            p1 = p1->left;
          }
          else
            break;
        }
        else if(k == p1->ele) {
          if (p1 == root) {
            if (p1->left == NULL){
              root = root->right;
              delete p1;
              p1 = NULL;
            }
            else if (p1->left != NULL) {
              if(p1->left->right == NULL) {
                root = root->left;
                root->right = p1->right;
              }
              else {
                node *a1 = p1->left;
                node *a2 = p1;
                while (a1->right != NULL){
                  a2 = a1;
                  a1 = a1->right;
                }
                root = a1;
                a1->right = p1->right;
                a2->right = a1->left;
                a1->left = p1->left;
              }
              delete p1;
              p1 = NULL;
            }
          }
          else if (p1->left == NULL) {
             if (p2->ele > p1->ele)
               p2->left = p1->right;
             if (p2->ele < p1->ele)
               p2->right = p1->right;
            delete p1;
             p1 = NULL;
          }
          else if(p1->left != NULL && p1->left->right == NULL) {
            if (p2->ele > p1->ele)
              p2->left = p1->left;
            if (p2->ele < p1->ele)
              p2->right = p1->left;
            p1->left->right = p1->right;
            delete p1;
             p1 = NULL;
          }
          else if(p1->left != NULL && p1->left->right != NULL) {
            node *a1 = p1->left;
            node *a2 = p1;
            while (a1->right != NULL){
              a2 = a1;
              a1 = a1->right;
            }
            if (p2->ele > p1->ele)
               p2->left = a1;
            if (p2->ele < p1->ele)
               p2->right = a1;
            a1->right = p1->right;
            a2->right = a1->left;
            a1->left = p1->left;
            delete p1;
            p1 = NULL;
          }
         break;
        }
      }
    }

    void BinaryTree::print() {
      preorder(root);
      cout<<endl;
    }
