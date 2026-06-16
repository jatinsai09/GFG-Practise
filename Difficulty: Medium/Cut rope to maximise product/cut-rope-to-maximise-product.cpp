class Solution {
  public:
    int maxProduct(int n) {
        // code here
        if (n <= 3) {
            return n - 1;
        }
        
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int l = max(j, dp[j]);
                int r = max(i - j, dp[i - j]);
                
                dp[i] = max(dp[i], l * r);
            }
            //cout << dp[i] << " ";
        }
        return dp[n];
    }
};