#include "MP.hpp"
#include <stack>
#include <iostream>
using namespace std;
using namespace MP;

int MaxPath::findMaxPath(TreeNode* root){
	if (root == NULL) return 0;
	else {
		max = 0;
		while (root->left->poi == 0 || root->right->poi == 0){
			int sum = 0;
			TreeNode* current = root;
			sum = root->val;
			while (current->left != NULL || current->right != NULL){
				if (current->left != NULL){
					if (current->left->poi == 0){
						sum += current->left->val;
						current = current->left;
					}
					else if (current->right != NULL){
						if (current->right->poi == 0){
							sum += current->right->val;
							current = current->right;
						}
						else break;
					}
					else break;
				}
				else if (current->right != NULL){
					if (current->right->poi == 0){
						sum += current->right->val;
						current = current->right;
					}
					else break;
				}
				else break;
			}
			current->poi = 1;
			max = (max > sum) ? max : sum;
		} 
		return max;
	}
}