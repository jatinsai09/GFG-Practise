
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        
        for(auto &coin: coins){
            for(int j = coin; j <= sum; j++){
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[sum];
    }
};

