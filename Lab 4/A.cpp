#include<bits/stdc++.h>

using namespace std;

int main(){
  int test;
  cin >> test;
  for(int t = 1; t<=test; t++){
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> point, query;
    vector<int> ans(q);
    for(int i = 0; i<n; i++){
      int a, b;
      cin >> a >> b;
      point.push_back({a, 0});
      point.push_back({b, 1});
    }
    sort(point.begin(), point.end());
    for(int i = 0; i<q; i++){
      int p;
      cin >> p;
      query.push_back({p, i});
    }
    sort(query.begin(), query.end());
    int count = 0, idx = 0, endZero = 0, end = 0;
    for(int i = 0; i< (int)point.size(); i++){
      if(point[i].second == 0){
        endZero++;
      }else{
        end++;
      }
      if(i<point.size() && point[i+1].first == point[i].first){
        continue;
      }
      while(idx < q && query[idx].first < point[i].first){
        ans[query[idx].second] = count;
        idx++;
      }
      count += endZero-end;
      endZero = 0;
      end = 0;
    }
    while(idx < q && query[idx].first < point.back().first){
      ans[query[idx].second] = count;
      idx++;
    }
    while(idx<q && query[idx].first == point.back().first){
      ans[query[idx].second] = count + endZero;
      idx++;
    }

    cout << "Case " << t << ":\n";
    for(int i = 0; i<q; i++){
      cout << ans[i] << "\n";
    }
  }
  return 0;
}
