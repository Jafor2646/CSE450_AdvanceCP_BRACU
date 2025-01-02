#include <iostream>
#define ll long long
#define ull unsigned long long;
using namespace std;
int matrix[52][52];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for(int t = 1; t<=test; t++){
    int n, m;
    int x = 0;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
      ll sum = 0;
      for(int j = 0; j<m; j++){
        cin >> matrix[i][j];
        sum += matrix[i][j];
      }
      x ^= sum;
    }  
    if(x) cout << "Case " << t << ": " << "Alice" << "\n";
    else cout << "Case " << t << ": " << "Bob" << "\n";
  }
  return 0;
}
