class Solution {
  public:
    int countPartitions(vector<int>& a, int d) {
        // Code here
        int n = a.size(), s = 0;
        for (auto &i: a) {
            s += i;
        }

        if ((s + d) % 2) return 0;
        
        int t = (s + d) / 2;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = t; j >= a[i]; j--) {
                dp[j] += dp[j - a[i]];
            }
        }

        return dp[t];
    }
};