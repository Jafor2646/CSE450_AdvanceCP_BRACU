#include <iostream>
#define ll long long
#define ull unsigned long long;
using namespace std;
int alice[102], bob[102];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for(int t = 1; t<=test; t++){
    int n;
    int x = 0;
    cin >> n;
    for(int i = 0; i<2*n; i++){
      if(i%2==0) cin >> alice[i/2];
      else cin >> bob[i/2];
    }
    for(int i = 0; i<n; i++){
      x ^= (bob[i] - alice[i] -1);
    }
    if(x) cout << "Case " << t << ": " << "Alice" << "\n";
    else cout << "Case " << t << ": " << "Bob" << "\n";
  }
  return 0;
}
