#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long;

const int maxLen = 1e6+7;
const int alphabets = 26;
int trie[maxLen][alphabets];
int totalNodes = 1;
int countChar[maxLen];

void add(string &s){
  int currNode = 1;
  countChar[currNode]++;

  for(int i = 0; i<s.size(); i++){
    int c = s[i] - 'a';
    if(trie[currNode][c]==0){
      totalNodes++;
      trie[currNode][c] = totalNodes;
    }

    currNode = trie[currNode][c];
    countChar[currNode]++;
  }
}

int query(string &s){
  int currNode = 1;
  for(int i = 0; i<s.size(); i++){
    int c = s[i] - 'a';
    if(trie[currNode][c]==0) return 0;
    currNode = trie[currNode][c];
  }
  return countChar[currNode];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  while(n--){
    string s;
    cin >> s;
    add(s);
  }
  while(q--){
    string s;
    cin >> s;
    cout << query(s) << endl;
  }

  return 0;
}