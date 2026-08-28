class Solution {
#define ll long long int
const ll MOD = 1e9 + 7;
  public:
    int countSubsequences(string& s, int n) {
        // code here
        vector<ll> dp(n, 0);

        for (auto& c : s) {
            int d = c - '0';

            vector<ll> ndp = dp;

            ndp[d % n]++;

            for (int r = 0; r < n; r++) {
                if (dp[r] == 0) continue;

                int nr = (r * 10 + d) % n;

                ndp[nr] = (ndp[nr] + dp[r]) % MOD;
            }

            dp = ndp;
        }

        return dp[0];
    }
};