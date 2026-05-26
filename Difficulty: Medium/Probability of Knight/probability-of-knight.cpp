class Solution {
  public:
    double findProb(int n, int x, int y, int k) {
        // Code here
        int di[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dj[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
        
        auto isValid = [&](int i, int j) -> bool {
          return (i >= 0 && j >= 0 && i < n && j < n);  
        };
        
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        if (isValid(x, y)) {
            dp[x][y] = 1.0;
        } else {
            return 0.0;
        }
        
        for (int i = 0; i < k; i++) {
            vector<vector<double>> next(n, vector<double>(n, 0.0));
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] == 0.0) {
                        continue;
                    }
                    
                    for (int k = 0; k < 8; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        
                        if (isValid(ni, nj)) {
                            next[ni][nj] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            dp = next;
        }
        
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[i][j];
            }
        }
        
        return res;
    }
};