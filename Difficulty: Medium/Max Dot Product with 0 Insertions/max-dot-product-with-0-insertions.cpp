class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (j == b.size()) {
                return 0;
            }
            
            if (i == a.size()) {
                return -1e9;
            }
            
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            
            int take0 = f(i + 1, j);
            int takeb = a[i] * b[j] + f(i + 1, j + 1);
            
            return dp[i][j] = max(take0, takeb);
        };
        
        return f(0, 0);
    }
};
