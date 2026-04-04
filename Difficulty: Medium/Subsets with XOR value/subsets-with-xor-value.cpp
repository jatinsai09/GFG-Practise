class Solution {
  public:
    int subsetXOR(vector<int> arr, int n, int k) {
        // code here
        int mx = 1024;
        vector<vector<int>> dp(n + 1, vector<int>(mx, 0));
    
        dp[0][0] = 1;
    
        for (int i = 1; i <= n; i++) {
            for (int x = 0; x < mx; x++) {
    
                dp[i][x] = dp[i - 1][x];
    
                dp[i][x] += dp[i - 1][x ^ arr[i - 1]];
            }
        }
    
        return dp[n][k];
    }
};