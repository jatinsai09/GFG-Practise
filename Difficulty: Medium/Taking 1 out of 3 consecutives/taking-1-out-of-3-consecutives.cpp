

class Solution {
  public:
    int minSum(vector<int>& arr) {
        // Write your code here
        int n = arr.size();
        if (n < 3) {
            return 0;
        }
        
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[2];
        
        for (int i = 3; i < n; i++) {
            dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + arr[i];
        }
        
        return min({dp[n - 1], dp[n - 2], dp[n - 3]});
    }
};