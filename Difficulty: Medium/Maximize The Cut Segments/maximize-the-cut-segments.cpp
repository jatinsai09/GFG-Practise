class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        
        for (int s = 1; s <= n; s++) {
            if (s >= x && dp[s - x] != -1) {
                dp[s] = max(dp[s], 1 + dp[s - x]);
            }
            if (s >= y && dp[s - y] != -1) {
                dp[s] = max(dp[s], 1 + dp[s - y]);
            }
            if (s >= z && dp[s - z] != -1) {
                dp[s] = max(dp[s], 1 + dp[s - z]);
            }
        }
        
        return (dp[n] == -1 ? 0 : dp[n]);
    }
};