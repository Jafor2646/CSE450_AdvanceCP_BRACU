#include <iostream>
#define ll long long
#define ull unsigned long long;
using namespace std;
int stones[102];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for(int t = 1; t<=test; t++){
    int n;
    int x = 0, flag = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
      cin >> stones[i];
      if(stones[i] != 1) flag = 1;
      x ^= stones[i];
    }
    if(flag){
      if(x) cout << "Case " << t << ": " << "Alice" << "\n";
      else cout << "Case " << t << ": " << "Bob" << "\n";
    }else{
      if(n%2) cout << "Case " << t << ": " << "Bob" << "\n";
      else cout << "Case " << t << ": " << "Alice" << "\n";
    }
  }
  return 0;
}
