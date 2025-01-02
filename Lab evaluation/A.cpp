#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, s, t;
  cin >> n;
  long long arr[n];
  for(long long i = 0; i<n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i< n-1; i++){
    cin >> s >> t;
    //cout << s << t << endl;
    long long temp = arr[i] / s;
    arr[i+1] += (t*temp);
    //cout << arr[i+1] << endl;
  }
  cout << arr[n-1] << endl;
  return 0;
}