class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        // code here
        int n = keys.size();
        vector<int> pre(n + 1);
        
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + freq[i - 1];
        }
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        
        
        for (int k = 0; k < n; k++) {
            for (int i = 1; i + k <= n; i++) {
                int j = i + k;
                int sum = pre[j] - pre[i - 1], res = 1e8;
                for (int m = i; m <= j; m++) {
                    res = min(res, dp[i][m - 1] + sum + dp[m + 1][j]);
                }
                dp[i][j] = res;
            }
        }
        
        return dp[1][n];
    }
};