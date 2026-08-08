class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int> cur(n);
        for (int j = 0; j < n; j++) {
            cur[j] = mat[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            int mxi = 0, sxi = -1;
            for (int j = 1; j < n; j++) {
                if (cur[j] >= cur[mxi]) {
                    sxi = mxi;
                    mxi = j;
                } else if (sxi == -1 || cur[j] > cur[sxi]) {
                    sxi = j;
                }
            }
            
            int mx1 = cur[mxi], mx2 = cur[sxi];
            for (int j = 0; j < n; j++) {
                cur[j] = (j == mxi ? mx2 : mx1) + mat[i][j];
            }
        }
        
        int res = 0;
        for (int j = 0; j < n; j++) {
            res = max(res, cur[j]);
        }
        
        return res;
    }
};