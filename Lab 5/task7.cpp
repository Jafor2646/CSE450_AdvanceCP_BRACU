#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

pair<int, int> moves[6] = {{-2, -1}, {-2, 1}, {-3, -1}, {-1, -2}, {-1, -3}, {1, -2}};

int board[507][507];


int mex(unordered_set<int> &tm){
  int g = 0;
  //cout << "Inside function" << endl;
  while(tm.find(g) != tm.end()){
    //cout << g << endl;
    g++;
  }
  //cout << "Outside function" << endl;
  return g;
}

int graundy(int x, int y){
  if(board[x][y] != -1) return board[x][y];
  unordered_set<int> temp;
  //cout << "coordinates" << endl;
  for(auto &move: moves){
    int i = x+move.first;
    int j = y+move.second;
    //cout << i << ", " << j << endl;
    if(i>=507 || j >= 507 || i < 0 || j < 0) continue;
    //cout << i << ", " << j << endl;
    temp.insert(graundy(i, j));
  } 
  //cout << "Set check" <<endl;
  //cout << "Size of set: " << temp.size() << endl;
  
  board[x][y] = mex(temp);
  return board[x][y];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(board, -1, sizeof(board));
  for(int i = 0; i<2; i++){
    for(int j = 0; j<2; j++){
      board[i][j] = 0;
    }
  }
  board[0][2] = 1;
  board[0][3] = 1;
  //board[1][2] = 1;
  //board[1][3] = 1;
  //board[1][4] = 1;
  board[2][0] = 1;
  //board[2][1] = 1;
  //board[2][2] = 1;
  //board[2][3] = 1;
  //board[2][4] = 1;
  board[3][0] = 1;
  //board[3][1] = 1;
  //board[3][2] = 1;
  //board[4][1] = 1;
  //board[4][2] = 1;
  int test,n, x, y, nim;
  cin >> test;
  for(int t = 1; t<=test; t++){
    cin >> n;
    nim = 0;
    for(int i = 0; i<n; i++){
      cin >> x >> y;
      nim ^= graundy(x, y);
      //cout << nim << " " << x << " " << y << ": " << t1 <<endl;
    }

    if(nim) cout << "Case " << t << ": " << "Alice" << "\n";
    else cout << "Case " << t << ": " << "Bob" << "\n";

  }

  return 0;
}
