// User function Template for C++

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // Code Here
        int n = arr.size();
        if(n == 1) return arr[0];
        if(n == 2) return arr[0] + arr[1];
        
        vector<long long> dp(n);
        
        dp[0] = arr[0];
        dp[1] = arr[0] + arr[1];
        dp[2] = max(dp[1], max((long long)arr[0] + arr[2], (long long)arr[1] + arr[2]));
        
        for(int i = 3; i < n; i++) {
            dp[i] = max(dp[i-1], max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]));
        }
        
        return dp[n-1];
    }
};