class Solution {
  public:
    int countAlwaysFound(vector<int>& a) {
        // code here
        int n = a.size();
        vector<int> smn(n);
        
        smn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            smn[i] = min(smn[i + 1], a[i]);
        }
        
        int res = 0, pmx = 0;
        for (int i = 0; i + 1 < n; i++) {
            res += (pmx < a[i] && smn[i + 1] > a[i]);
            
            pmx = max(pmx, a[i]);
        }
        res += (pmx < a[n - 1]);
        
        return res;
    }
};