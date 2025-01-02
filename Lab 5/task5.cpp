#include <iostream>
#include <set>
#define ll long long
#define ull unsigned long long;
using namespace std;
int grundy[10000+7];
int piles[105];
void preCompute(){
  grundy[1] = 1;
  grundy[2] = 0;
  set <int> store;
  for(int i = 3; i < 10007; i++){
    int j;
    store.clear();
    if(i % 2 == 0) j = i/2;
    else j = (i/2)+1;
    for(int k = 1; k<j; k++){
      store.insert(grundy[k] ^ grundy[i-k]);
    }
    int res = 0;
    while(store.find(res) != store.end()) ++res;
    grundy[i] = res;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  preCompute();
  int test, n;
  cin >> test;
  for(int t = 1; t<=test; t++){
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> piles[i];
    }
    int x = 0;
    for(int i = 0; i<n; i++){
      x ^= grundy[piles[i]];
    }
    if(x) cout << "Case " << t << ": " << "Alice" << "\n";
    else cout << "Case " << t << ": " << "Bob" << "\n";
  }
  return 0;
}
