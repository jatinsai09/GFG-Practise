class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> right(n, vector<int>(n)), down(right);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 'X') {
                    right[i][j] = 1;
                    down[i][j] = 1;
                    
                    if (j + 1 < n) {
                        right[i][j] += right[i][j + 1];
                    }
                    if (i + 1 < n) {
                        down[i][j] += down[i + 1][j];
                    }
                }
            }
        }
        
        for (int k = n; k >= 1; k--) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (right[i][j] < k || down[i][j] < k) {
                        continue;
                    }
                    
                    if (right[i + k - 1][j] < k) {
                        continue;
                    }
                    if (down[i][j + k - 1] < k) {
                        continue;
                    }
                    
                    return k;
                } 
            }
        }
        
        return 0;
    }
};