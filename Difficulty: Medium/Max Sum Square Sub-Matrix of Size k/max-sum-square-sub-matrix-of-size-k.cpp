class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();
        vector<vector<int>> ps(n + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ps[i][j] = mat[i - 1][j - 1]
                            + ps[i - 1][j] + ps[i][j - 1]  
                            - ps[i - 1][j - 1];
            }
        }
        
        int res = ps[k][k];
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                int got = ps[i][j] 
                - ps[i - k][j] - ps[i][j - k] 
                + ps[i - k][j - k];
                
                res = max(res, got);
            }
        }
        
        return res;
    }
};