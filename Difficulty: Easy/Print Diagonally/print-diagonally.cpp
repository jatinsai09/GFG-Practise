class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        vector<int> res;
        
        for (int col = 0; col < n; col++) {
            for (int i = 0, j = col; j >= 0 && i < n; j--, i++) {
                res.push_back(mat[i][j]);
            }
        }
        
        for (int row = 1; row < n; row++) {
            for (int i = row, j = n - 1; j >= 0 && i < n; j--, i++) {
                res.push_back(mat[i][j]);
            }
        }
        
        return res;
    }
};