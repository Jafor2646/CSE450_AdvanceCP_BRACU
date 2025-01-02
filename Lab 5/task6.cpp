#include <iostream>
#include <set>
#define ll long long
#define ull unsigned long long
using namespace std;
int piles[1005];
int grundy(int x){
  if(x == 0 || x == 1) return 0;
  if(x%2 == 0) return x/2;
  return grundy(x/2);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test, n;
  cin >> test;
  for(int t = 1; t<=test; t++){
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> piles[i];
    }
    int x = 0;
    for(int i = 0; i<n; i++){
      x ^= grundy(piles[i]);
    }
    if(x) cout << "Case " << t << ": " << "Alice" << "\n";
    else cout << "Case " << t << ": " << "Bob" << "\n";
  }
  return 0;
}
