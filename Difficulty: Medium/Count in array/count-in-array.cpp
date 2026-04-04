class Solution {
#define ll long long int
  public:
    long long count(long long n, long long m) {
        // code here
        ll mod = 1000000007;

        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    
        for (int x = 1; x <= m; x++) {
            dp[1][x] = 1;
        }
    
        for (int i = 2; i <= n; i++) {
    
            for (int x = 1; x <= m; x++) {
    
                for (int d = 1; d * d <= x; d++) {
                    if (x % d) {
                        continue;
                    }
    
                    dp[i][x] = (dp[i][x] + dp[i - 1][d]) % mod;

                    if (d != x / d) {
                        dp[i][x] = (dp[i][x] + dp[i - 1][x / d]) % mod;
                    }
                    
                }
    
                for (int mul = x * 2; mul <= m; mul += x) {
                    dp[i][x] = (dp[i][x] + dp[i - 1][mul]) % mod;
                }
            }
        }
    
        ll res = 0;
        for (int x = 1; x <= m; x++) {
            res = (res + dp[n][x]) % mod;
        }
    
        return res;
    }
};