class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        for (int col = 0; col < m; col++) {
            int i = 0, j = col;
            int val = mat[i][j];
            while (i < n && j < m) {
                if (mat[i++][j++] != val) {
                    return false;
                }
            }
        }
        
        for (int row = 1; row < n; row++) {
            int i = row, j = 0;
            int val = mat[i][j];
            while (i < n && j < m) {
                if (mat[i++][j++] != val) {
                    return false;
                }
            }
        }
        
        return true;
    }
};