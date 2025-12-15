// User function Template for C++

class Solution {
  public:
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        vector<vector<int>> dp(n + 1, vector<int>(3));
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + colors[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + colors[i - 1][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + colors[i - 1][2];
        }
        
        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};
