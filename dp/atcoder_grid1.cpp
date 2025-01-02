#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const int MOD = 1e9+7;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for(int i =0; i<n; i++){
    cin >> s[i];
  }
  vector<vector<int>> dp(n,vector<int>(m));
  dp[0][0];
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(s[i][j] == '#' || (i == 0 && j ==0)) continue;
      if(i == 0) dp[i][j] = dp[i][j-1];
      else if(j == 0) dp[i][j] = dp[i-1][j];
      else a[i][j] = (dp[i][j]%MOD + dp[i-1][j]%MOD + dp[i][j-1]%MOD)%MOD;

    }
  }
  cout << a[n-1][m-1] << "\n";
  return 0;
}
