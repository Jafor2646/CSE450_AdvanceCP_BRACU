#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long;

const ll p = 1e9+9;
const ll x = 1e5+1;
const ll nmax = 1e7+10000;

ll H[nmax];
ll power[nmax];

void precal() {
  power[0] = 1;
  for(int i = 1; i<nmax; i++){
    power[i] = (power[i-1]*x)%p;
  }
}

void buildHash(string &s){
  H[0] = s[0];
  for(int i = 0; i<s.size(); i++){
    H[i] = (H[i-1]*x + s[i])%p;
  }
}

ll hashVal(int l, int r){
  ll result = H[r];
  if(l == 0){
    return result;
  }
  result -= H[l-1]*power[r-l+1];
  result %= p;
  if(result < 0) result += p;
  return result;
}
ll fullSringHashVal(string &s){
  ll result = s[0];
  for(int i = 1; i<s.size(); i++){
    result = (result*x+s[i])%p;
  }
  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  precal();
  string s1, s2;
  int test;
  cin >> test;
  for(int t = 0; t<test;t++){
    cin >> s1 >> s2;
    buildHash(s2);
    int  counter = 0;
    ll secondHash = hashVal(0, s2.size()-1);
    buildHash(s1);
    for(int i = 0; i+s2.size()-1<s1.size();i++){
      if(hashVal(i, i+s2.size()-1) == secondHash) counter++;
    }
    if(counter == 0) cout << "Not Found";
    else{
      cout << counter << endl;
      for(int i = 0; i+s2.size()-1<s1.size();i++){
        if(hashVal(i, i+s2.size()-1) == secondHash) cout << i+1 << ' ';
      }
    }
    if(t != (test-1)) cout << "\n\n";
  }
  return 0;
}