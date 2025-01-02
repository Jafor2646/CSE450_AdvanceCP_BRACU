#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;

#define ll long long
#define ull unsigned long long;

// struct trie{
//   ll stop;
//   trie* next[10];
//   trie(){
//     stop = 0;
//     for(int i = 0; i < 10; i++){
//       next[i] = NULL;
//     }
//   }
// };

// trie * root;

// bool insertTrie(string st, trie* curr){
//   cout<<"Inside func1" << endl;
//   int l = st.size();
//   cout<<"Inside func2" << endl;
//   bool testInsert = 0;
//   cout<<"Inside func3" << endl;
//   for(int i = 0; i<l; i++){
//     cout<<"Inside func4" << endl;
//     int now = st[i] - '0';
//     cout<<"Inside func5" << endl;
//     if(curr->next[now] == NULL){
//       curr->next[now] = new trie();
//     } 
//     cout<<"Inside func6" << endl;
//     if(curr->stop){
//       cout<<"Inside func7" << endl;
//       testInsert = 1;
//       cout<<"Inside func8" << endl;
//       break;
//     }
//     cout<<"Inside func9" << endl; 
//     curr = curr->next[now];
//   }
//   cout<<"Inside func10" << endl;
//   curr->stop = 1;
//   cout<<"Inside func11" << endl;
//   return testInsert;
// }

// int main() {

//   int test;
//   cin >> test;
//   for(int t = 1; t<=test;t++){
//     int n;
//     cin >> n;
//     vector<string> store;
//     for(int i = 0; i<n; i++){
//       string a;
//       cin >> a;
//       store.push_back(a);
//     }
//     cout << "Before Insert" << endl;    
//     bool flag = 0;
//     for(int i = 0; i<n; i++){
//       flag = insertTrie(store[i], root);
//       cout << "During Insert" << endl;

//       if(flag) break;
//     }
//     cout << "After Insert" << endl;
//     if(flag){
//       cout << "Case " << t << ": NO" << endl;
//     }else{
//       cout << "Case " << t << ": YES" << endl;
//     }
//   }
//   return 0
// }


struct node
{
	bool endmark;
	node *next[10+1];
	node()
	{
		endmark=false;
		for(int i=0;i<10;i++) next[i]=NULL;
	}
}*root;
 
void insert(char *str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark=1;
 
}
bool search(char *str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		//if(curr->next[id]==NULL) return false;
		curr=curr->next[id];
	}
	for(int id=0;id<10;id++)
	{
	    if(curr->next[id]!=NULL)return false;
	}
	return true;
}
 
 
 
void del(node *cur)
{
      for(int i=0;i<10;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;
          delete(cur) ;
}
 
 
 
char S[10009][12];
 
int main(){
    //filer();
    int i,j,k ,T,cas=0;
    //scanf("%d%d",,&N,&T);
    scanf("%d",&T);
    int n;
 
    while(T--)
    {
        root=new node();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",S[i]);
            insert(S[i],strlen(S[i]));
        }
        bool t=1;
        for(i=0;i<n;i++)
        {
            t=search(S[i],strlen(S[i]));
            if(!t)break;
        }
        if(!t)printf("Case %d: NO\n",++cas);
        else printf("Case %d: YES\n",++cas);
        del(root);
    }
 
   

 return 0;
}