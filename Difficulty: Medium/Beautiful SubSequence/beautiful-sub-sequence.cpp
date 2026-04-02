
class Solution {
  public:
    int longest_Subsequence(vector<int>& arr) {
        // Complete the function
        int n = arr.size();
        sort(begin(arr), end(arr));
        vector<int> dp(n, 1);
        
        int res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        
        return res == 1 ? -1 : res;
    }
};