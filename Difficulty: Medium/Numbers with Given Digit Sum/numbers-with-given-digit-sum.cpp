class Solution {
  public:
    int countWays(int n, int sum) {
        // code here
        vector<vector<int>> dp(sum + 1, vector<int>(n + 1));
        
        dp[0][0] = 1;
        for (int s = 1; s <= 9; s++) {
            if (s > sum) {
                break;
            }
            dp[s][1] = 1;
        }
        
        for (int c = 2; c <= n; c++) {
            for (int s = 1; s <= sum; s++) {
                for (int i = 0; i <= 9; i++) {
                    if (i > s) {
                        break;
                    }
                    
                    dp[s][c] += dp[s - i][c - 1];
                }
            }
        }
        
        return (dp[sum][n] ? dp[sum][n] : -1);
     }
};