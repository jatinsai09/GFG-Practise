class Solution {
  public:
    int countWays(string &s) {
        // Code here
        int n = s.size();
        s = " " + s;
        if (s[1] == '0') {
            return 0;
        }
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};