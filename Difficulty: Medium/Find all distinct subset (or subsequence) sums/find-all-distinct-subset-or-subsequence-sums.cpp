class Solution {
  public:
    vector<int> DistinctSum(vector<int> nums) {
        // Code here
        vector<int> res;
        int s = 0;
        for (auto &i: nums) {
            s += i;
        } 
        
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        
        for (auto &val: nums) {
            for (int i = s; i >= val; i--) {
                if (dp[i - val]) {
                    dp[i] = 1;
                }
            }
        }
        
        for (int i = 0; i <= s; i++) {
            if (dp[i]) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};