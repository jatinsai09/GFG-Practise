class Solution {
  public:
    int minDeletions(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                
                if (len == 2) {
                    dp[i][j] = (s[i] == s[j] ? 0 : 1);
                } else if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        
        return dp[0][n - 1];
    }
};