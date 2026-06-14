class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> dir = {0, 1, 0, -1, 0};
        
        int cd = 0, cr = 0, cc = 0;
        while (1) {
            if (mat[cr][cc]) {
                mat[cr][cc] = 0;
                cd++;
                cd %= 4;
            }
            
            int nr = cr + dir[cd], nc = cc + dir[cd + 1];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                return {cr, cc};
            }
            
            cr = nr;
            cc = nc;
        }
        
        return {-1, -1};
    }
};