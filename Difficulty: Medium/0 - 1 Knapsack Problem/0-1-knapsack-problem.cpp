
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        
        for (int j = wt[0]; j <= W; j++){
            dp[0][j] = val[0];
        }
        
        for (int i = 1; i < n; i++) {
            for(int j = 0 ; j <= W; j++) {
                int notTake = dp[i - 1][j], take = INT_MIN;
                if(wt[i] <= j){
                    take = val[i] + dp[i - 1][j - wt[i]];
                }
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};

