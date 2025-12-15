// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n <= 2) {
            return n;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int res = 2;
        
        for (int j = n - 2; j > 0; j--) {
            int i = j - 1, k = j + 1;
            
            while (i >= 0 && k < n) {
                if (arr[i] + arr[k] > 2 * arr[j]) {
                    i--;
                } else if (arr[i] + arr[k] < 2 * arr[j]) {
                    k++;
                } else {
                    dp[i][j] = dp[j][k] + 1;
                    res = max(res, dp[i][j]);
                    i--;
                    k++;
                }
            }
        }
        
        return res;
    }
};