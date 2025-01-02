#include <bits/stdc++.h>

using namespace std;

int main(){
  int test;
  cin >> test;
  for(int t = 0; t< test; t++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i<n; i++){
      if(s[i] == 'p'){
        if(i > 1 && i < n-2 && ((s[i-2] == 'm' && s[i-1] == 'a') || (s[i+1] == 'i' && s[i+2] == 'e'))){
          ++count;
        }else if( i < n-2 && s[i+1] == 'i' && s[i+2] == 'e') ++count;
        else if(i > 1 && s[i-2] == 'm' && s[i-1] == 'a') ++count;
        
      }
    }
    cout << count << endl;
  }
  
  return 0;
}