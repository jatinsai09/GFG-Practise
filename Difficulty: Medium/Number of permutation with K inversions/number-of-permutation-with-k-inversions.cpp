class Solution {
  public:
    int countPermWithkInversions(int n, int k) {
        // code here
        
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i][j - 1];
                dp[i][j] = (dp[i][j] + dp[i - 1][j]);
                
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i]);
                }
            }
        }
        
        return dp[n][k];
    }
};