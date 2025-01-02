#include <bits/stdc++.h>

using namespace std;

class TrieNode() {
  public:
    TrieNode(){
      for(int i =0; i<4; i++){
        child[i] = nullptr;
      }
      len = 0;
      pref = 0;
    }
    TrieNode* child[4];
    int len;
    int pref;
};

void insert(TrieNode* node, const string &str){
  int length = str.length();
  TrieNode* curr = node;
  for(int i =0; i<length; ++i){
    int idx;
    if(str[i] == 'A') idx = 0;
    else if(str[i] == 'C') idx = 1;
    else if(str[i] == 'G') idx = 2;
    else idx = 3;
    int add = curr->len;
    if(!curr->child[idx]) curr->child[idx] = new TrieNode();
    curr = curr->child[idx];
    curr->len = add+1;
    curr->pref += 1;
  }
}

void delTrie(TrieNode* node){
  for(int i = 0; i<4; ++i){
    if(node->child[i] != nullptr) delTrie(node->child[i]);
  }
  delete node;
}