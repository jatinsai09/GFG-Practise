
class Solution {
  public:
    int count(vector<int>& arr) {
        // code here
        int n = arr.size(), res = n + 1;
        
        vector<vector<int>> dp(n, vector<int>(202, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = arr[i] - arr[j] + 100, add = 1 + dp[j][d];
                dp[i][d] += add;
                res += add;
            }
        }
        
        return res;
    }
};