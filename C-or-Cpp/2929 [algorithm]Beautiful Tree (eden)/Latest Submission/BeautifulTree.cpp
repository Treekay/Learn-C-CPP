 #include <iostream>
#include "BeautifulTree.hpp"
using namespace std;
using namespace HFM;
HuffmanCode::HuffmanCode(const string &str) {
  num_count = 0;
  root = NULL;
  message = str;
  cleanblank();
  count_weight();
  build_tree();
}

HuffmanCode::~HuffmanCode() {
    clear(root);
}
HuffmanCode::HuffmanCode(int w[], int n) {
  num_count = n;
  root = NULL;
  for (int i = 0; i < num_count; ++i){
    all_num[i].weight = w[i];
    all_num[i].count = i;
  }
  sort();
  build_tree();
}
void HuffmanCode::build_tree() {
  vector<node*> vec_node;
  for (int i = 0; i < num_count; ++i) {
    node *p = new node(all_num[i]);
    vec_node.push_back(p);
  }
  while (vec_node.size() > 1) {
    num mid(vec_node[0]->ele.weight + vec_node[1]->ele.weight);
    node *p = new node(mid);
    p->left = vec_node[0];
    p->right = vec_node[1];
    vec_node[0]->c = '1';
    vec_node[1]->c = '0';
    vec_node.erase(vec_node.begin());
    vec_node.erase(vec_node.begin());
    vector<node*>::iterator ite = vec_node.begin();
    for ( ; ite != vec_node.end(); ++ite)
      if (mid.weight < (*ite)->ele.weight)
        break;
    vec_node.insert(ite, p);
  }
  root = vec_node[0];
  root->c = 'R';
}

  
void HuffmanCode::count_weight() {
  int wei[26] = {0};
  char alp[26];
  char a = 'a';
  for (int i = 0; i < 26; ++i)
    alp[i] = a++;
  for (int i = 0; i < message.length(); ++i)
    wei[message[i]- 97]++;
  for (int i = 0; i < 26; ++i) {
    if (wei[i] != 0) {
      all_num[num_count].cha = alp[i];
      all_num[num_count].weight = wei[i];
      ++num_count;
    }
  }
  sort();
}
void HuffmanCode::DisplayCode() {
  string a;
  getcode(root, a);
  int length = 0;
  if (all_num[0].cha == ' ') {
    for (int i = 0; i < num_count; ++i) {
      cout << "Weight = " << all_num[i].weight << "; Code = " << all_num[i].str << endl;
      length += all_num[i].weight * all_num[i].str.length();
    }
    cout << "Huffman's codeLength = " << length << endl;
  }
  else {
    for (int i = 0; i < num_count; ++i) {
      cout << '(' << all_num[i].cha << ')' << " Weight = " << all_num[i].weight << "; Code = " << all_num[i].str << endl;
      length += all_num[i].weight * all_num[i].str.length();
    }
    cout << "Huffman's codeLength = " << length << endl;
    cout << "Origin Text: " << message << endl;
    cout << "Huffman's Code: ";
    for (int i = 0; i < message.length(); ++i) {
      for (int j = 0; j < num_count; ++j) {
        if (message[i] == all_num[j].cha) {
          cout << all_num[j].str;
          break;
        }
      }
    }
    cout << endl;
  }
}
void HuffmanCode::getcode(node *p, string a) {
    if (p != NULL) {
      if (p->c != 'R')
        a += p->c;
    if (p->left == NULL && p->right == NULL) {
      if (p->ele.cha == ' ') {
        for (int i = 0; i < num_count; ++i) {
          if (p->ele.count == all_num[i].count) {
            all_num[i].str = a;
            return;
          }
        }
      }
      else {
        for (int i = 0; i < num_count; ++i) {
          if (p->ele.cha == all_num[i].cha) {
            all_num[i].str = a;
            return;
          }
        }
      }
    }
    getcode(p->left, a);
    getcode(p->right, a);
  }
}
void HuffmanCode::sort() {
  for (int i = num_count - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (all_num[j].weight > all_num[j + 1].weight) {
        num mid = all_num[j];
        all_num[j] = all_num[j + 1];
        all_num[j + 1] = mid;
      }
      else if (all_num[j].weight == all_num[j + 1].weight) {
        if (all_num[j].cha > all_num[j + 1].cha) {
          num mid = all_num[j];
          all_num[j] = all_num[j + 1];
          all_num[j + 1] = mid;
        }
      }
    }
  }
}
void HuffmanCode::clear(node * p) {
    if (p != NULL) {
    clear(p->left);
    clear(p->right);
    delete p;
  }
}
void HuffmanCode::cleanblank() {
  string mid;
  for (int i = 0; i < message.length(); ++i)
    if (message[i] != ' ')
      mid += message[i];
  message = mid;
}