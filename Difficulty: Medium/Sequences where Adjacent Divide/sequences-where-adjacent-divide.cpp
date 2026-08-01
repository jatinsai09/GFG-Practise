class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
  public:
    int count(int n, int m) {
        // code here
        if (n == 1) {
            return m;
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int x = 1; x <= m; x++) {
            dp[1][x] = 1;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int x = 1; x <= m; x++) {
                for (int mul = x * 2; mul <= m; mul += x) {
                    dp[i][x] = (dp[i][x] + dp[i - 1][mul]) % mod;
                }
                for (int d = 1; d * d <= x; d++) {
                    if (x % d) {
                        continue;
                    }
                    
                    dp[i][x] = (dp[i][x] + dp[i - 1][d]) % mod;
                    if (x / d != d) {
                        dp[i][x] = (dp[i][x] + dp[i - 1][x / d]) % mod;
                    }
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