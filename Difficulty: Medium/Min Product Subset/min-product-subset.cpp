class Solution {
  public:
    int minProd(vector<int>& a) {
        // code here
        int p = 1, cn = 0;
        for (auto &i: a) {
            if (i) {
                p *= i;
            }
            cn += (i < 0);
        }
        
        if (p < 0) {
            return p;
        }
        
        if (cn == 0) {
            int mn = INT_MAX;
            for (auto &i: a) {
                mn = min(mn, i);
            }
            return mn;
        } 
        
        int mx = INT_MIN;
        for (auto &i: a) {
            if (i < 0) {
               mx = max(mx, i); 
            }
        }
        
        return p / mx;
    }
};