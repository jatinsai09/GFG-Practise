class Solution {
  public:
    int getMaxWeight(string &s) {
        // code here
        int n = s.size();
        
        if (n == 1) {
            return 1;
        }

        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = (s[0] != s[1] ? 4 : 3);
        
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + 1;
            dp[i] = max(dp[i], dp[i - 2] + 4 - (s[i] == s[i - 1]));
        }
        return dp[n - 1];
    }
};
