class Solution {
  public:
    int count(int N) {
        // code here
        int k = N / 2;
        vector<int> dp(k + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        
        return dp[k];
    }
};