class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        
        int xr = 0;
        for (auto &i: arr) {
            xr ^= i;
        }
        
        int lsb = xr & -xr, x = 0;
        for (auto &i: arr) {
            if (lsb & i) {
                x = x ^ i;
            }
        }
        
        if (x > (xr ^ x)) {
            return {xr ^ x, x};
        } else {
            return {x, xr ^ x};
        }
    }
};