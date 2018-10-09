 #ifndef BEAUTIFULTREE_H
#define BEAUTIFULTREE_H
#include <iostream>
#include <vector>
using namespace std;
namespace HFM {
	typedef struct num {
		char cha = ' ';
		int count = 0;
		int weight = 0;
		string str = "";
		num(int b = 0, char a = ' ', bool c = false, string d = "") {
			cha = a;
			weight = b;
			str = d;
			count = 0;
		}
	}num;
	typedef struct node {
		num ele;
		char c;
		node* right;
		node* left;
		node(num ano, char a = '\0', node* r = NULL, node * l = NULL) {
			c = a;
			ele = ano;
			right = r;
			left = l;		
		}
	}node;
  class HuffmanCode {
    public:
      HuffmanCode(const string &str);
      ~HuffmanCode();
      HuffmanCode(int w[], int n);
      void build_tree();
      void count_weight();
      void DisplayCode();
      void getcode(node *p, string a);
      void sort();
      void clear(node * p);
      void cleanblank();
    private:
    	num all_num[20];
    	int num_count;
      string message;
      node *root;
 };
}

#endif