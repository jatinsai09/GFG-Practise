class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) >> 1, idx = 0;
            
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[idx][mid]) {
                    idx = i;
                }
            }
            
            int left = (mid - 1 >= 0) ? mat[idx][mid - 1] : INT_MIN;
            int right = (mid + 1 < m) ? mat[idx][mid + 1] : INT_MIN;
            
            if (mat[idx][mid] >= left && mat[idx][mid] >= right) {
                return {idx, mid};
            }
            else if (left > mat[idx][mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};
