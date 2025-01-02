#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int mod_inv(int a, int m){
  int x, y;
  int g = extended_euclidean(a, m, x, y);
  if (g != 1) {
      cout << "No solution!";
      return -1;
  }
  else {
      x = (x % m + m) % m;
  }
  return x;
}

//another way
int inv(int a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

int main(){
  ios:sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, m;

  int m_inv = mod_inv(a, m);
  if(m_inv != -1) cout << m_inv << endl;  
  return 0;
}