class Solution {
  public:
    int minDiff(int k, vector<int> &a) {
        // code here
        int n = a.size();
        vector<int> smx(n), smn(n);
        smx[n - 1] = smn[n - 1] = a[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            smx[i] = max(smx[i + 1], a[i]);
            smn[i] = min(smn[i + 1], a[i]);
        }
        
        int res = smx[k] - smn[k];
        int pmn = a[0], pmx = a[0];
        for (int i = 0; i + k + 1 < n; i++) {
            pmn = min(pmn, a[i]);
            pmx = max(pmx, a[i]);
            
            int mx = max(pmx, smx[i + k + 1]);
            int mn = min(pmn, smn[i + k + 1]);
            
            res = min(res, mx - mn);
        }
        
        pmn = min(pmn, a[n - k - 1]);
        pmx = max(pmx, a[n - k - 1]);
        
        res = min(res, pmx - pmn);
        
        return res;
    }
};
