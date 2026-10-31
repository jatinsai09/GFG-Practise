class Solution {
  public:
    int maxPackages(vector<int>& a, int k) {
        // code here
        int n = a.size(), res = 0, s = 0;
        
        for (int i = 0; i < n; i++) {
            s += a[i];
            if (i >= k) {
                s -= a[i - k];
            }
            
            res = max(res, s);
            
        }
        
        return res;
    }
};