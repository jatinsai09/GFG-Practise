class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        vector<vector<int>> ps(n + 1, vector<int>(m + 1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i + 1][j + 1] = mat[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
            }
        }
        
        for(const auto& q: queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            int s = ps[r2 + 1][c2 + 1] - (ps[r2 + 1][c1] + ps[r1][c2 + 1]) + ps[r1][c1];
            res.push_back(s);
        }
        
        return res;
    }
};
