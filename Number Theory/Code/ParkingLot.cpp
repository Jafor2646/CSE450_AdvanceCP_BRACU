#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;

  ll total = 2*4*3*binpow(4,n-3)+(n-3)*4*3*3*binpow(4, n-4);

  cout << total << "\n";
  return 0;
}