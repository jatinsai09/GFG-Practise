class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = i;
        
        for (int j = 2; j <= n; j++) {
            dp[j] = min(dp[j - 1] + i, dp[(j + 1) / 2] + c + (j & 1) * d);
        }
        
        return dp[n];
    }
};
