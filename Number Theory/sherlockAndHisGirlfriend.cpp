#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  vector<int> s(n+2, 0);
  for(int i = 2; i<2+n;i++){
    if(s[i] != 0) continue;
    for(int j = i; j<2+n; j+=i){
      if(s[i] == 0) s[j] = 1;
      else s[j] = 2;
    }
  }
  if(n>2) cout<<2<<endl;
  else cout << 1<< endl;

  for(int i = 2; i<2+n; i++) cout << s[i] << ' ';
  cout<<"\n";
  return 0;
}