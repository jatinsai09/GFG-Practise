class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n = arr.size(), sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        if(abs(target) > sum || (sum + target) % 2) {
            return 0;
        }
        
        int req = (sum + target) / 2;
        
        vector<int> dp(req + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = req; j >= arr[i]; j--)
            {
                dp[j] += dp[j - arr[i]];
            }
        }
        
        return dp[req];
    }
};