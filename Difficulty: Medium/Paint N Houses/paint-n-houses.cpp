// User function Template for C++

class Solution {
  public:
  #define ll long long int
    long long int distinctColoring(int n, int r[], int g[], int b[]) {
        // code here
        vector<vector<ll>> dp(n + 1, vector<ll>(3));
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i - 1];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i - 1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i - 1];
        }
        
        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};