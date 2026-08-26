class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        vector<int> h(m, 0);
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    h[j] = 0;
                } else {
                    h[j]++;
                }
            }
            
            vector<int> v = h;
            sort(rbegin(v), rend(v));
            
            for (int j = 0; j < m; j++) {
                res = max(res, v[j] * (j + 1));
            }
        }
        return res;
    }
};