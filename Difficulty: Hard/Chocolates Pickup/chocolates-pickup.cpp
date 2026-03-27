class Solution {
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        function<int(int, int, int)> f = [&](int i, int j1, int j2) -> int {
            if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
                return INT_MIN;
            }
            
            if (i == n - 1) {
                if (j1 == j2) {
                    return grid[i][j1];
                } else {
                    return grid[i][j1] + grid[i][j2];
                }
            }
            
            if (dp[i][j1][j2] != -1) {
                return dp[i][j1][j2];
            }
            
            int base = 0, val;
            if (j1 == j2) {
                base = grid[i][j1]; 
            } else {
                base = grid[i][j1] + grid[i][j2];
            }
            
            int res = 0;
            for (int dj1 = -1; dj1 <= 1; dj1++) {
                for (int dj2 = -1; dj2 <= 1; dj2++) {
                    val = base + f(i + 1, j1 + dj1, j2 + dj2);
                    res = max(res, val);
                }
            }
            
            return dp[i][j1][j2] = res;
        };
        
        return f(0, 0, m - 1);
    }
};