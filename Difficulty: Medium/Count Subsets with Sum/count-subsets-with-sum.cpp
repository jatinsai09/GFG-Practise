class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int> dp(target + 1);
        
        dp[0] = 1;
        for (const auto &c: arr) {
            for (int s = target; s >= c; s--) {
                dp[s] += dp[s - c];
            }
        }
        
        return dp[target];
    }
};