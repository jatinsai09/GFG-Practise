class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            bool yes = false;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    res += yes;
                } else {
                    yes = true;
                }
            }
            yes = false;
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    res += yes;
                } else {
                    yes = true;
                }
            }
        }
        
        for (int j = 0; j < m; j++) {
            bool yes = false;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 0) {
                    res += yes;
                } else {
                    yes = true;
                }
            }
            yes = false;
            for (int i = n - 1; i >= 0; i--) {
                if (mat[i][j] == 0) {
                    res += yes;
                } else {
                    yes = true;
                }
            }
        }
        
        return res;
    }
};
