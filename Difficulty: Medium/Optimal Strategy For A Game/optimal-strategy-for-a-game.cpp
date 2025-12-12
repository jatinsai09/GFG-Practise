class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i + k < n; i++) {
                int j = i + k;
                if (i == j) {
                    dp[i][j] = arr[i];
                } else if (i + 1 == j) {
                    dp[i][j] = max(arr[i], arr[j]);
                } else {
                    dp[i][j] = max(
                        arr[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
                        arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2])
                    );
                }
            }
        }
        
        return dp[0][n - 1];
    }
};