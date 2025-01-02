#include <iostream>
#define ll long long
#define ull unsigned long long;
using namespace std;
int white[102], black[102];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for(int t = 1; t<=test; t++){
    int n;
    int x = 0;
    cin >> n;
    for(int i = 1; i<=n; i++){
      cin >> white[i];
    }
    for(int i = 1; i<=n; i++){
      cin >> black[i];
      x ^= (black[i] - white[i] -1);
    }
    if(x) cout << "Case " << t << ": " << "white wins" << "\n";
    else cout << "Case " << t << ": " << "black wins" << "\n";
  }
  return 0;
}
