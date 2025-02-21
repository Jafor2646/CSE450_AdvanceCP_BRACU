#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        int m = word1.size(), n = word2.size();
        if(m == 0 || n == 0) return max(m, n);
        vector <vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 0; i<= n; i++){
            dp[0][i] = i;
        }
        for(int i = 0; i<=m; i++){
            dp[i][0] = i;
        }
        for(int i =1; i<= m; ++i){
            for(int j = 1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
            }
        }
        return dp[m][n];
 
    }
};