class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<long long> dp(x + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            vector<long long> ndp(x + 1, 0);
            for (int s = 1; s <= x; s++)
            {
                for (int f = 1; f <= m; f++)
                {
                    if (s - f >= 0)
                    {
                        ndp[s] += dp[s - f];
                    }
                }
            }
            dp = ndp;
        }

        return dp[x];
    }
};