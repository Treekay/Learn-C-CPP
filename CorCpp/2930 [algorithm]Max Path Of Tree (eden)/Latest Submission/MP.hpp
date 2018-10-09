 #ifndef MP_H_
#define MP_H_
#include <iostream>
namespace MP {
	struct TreeNode{
		int val;//the weight of this node
		int id;
		int poi;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x, int i){
			val = x;
			id = i;
			left = NULL;
			right = NULL;
			poi  =0;
		}
	};

	class MaxPath {
	private:
	    int max;
	public:
	    MaxPath() : max(0) {}
	    int findMaxPath(TreeNode *root);
	};
}

#endif