class Solution {
  public:
    const long long mod = 1000000007;
    int distinctSubseq(string &str) {
        // code here
        int n = str.size();
        vector<long long> prev(26, -1), dp(n + 1);
        dp[0] = 1LL;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] << 1LL) % mod;
            char c = str[i - 1];
            if (prev[c - 'a'] != -1) {
                dp[i] = (dp[i] - dp[prev[c - 'a'] - 1] + mod) % mod;
            }
            prev[c - 'a'] = i;
        }
        return dp[n];
    }
};