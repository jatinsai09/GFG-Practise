class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int n = arr.size(), ind = 0;
        
        for (int b = 31; b >= 0 && ind < n; b--) {
            int mxi = ind;
            for (int i = ind; i < n; i++) {
                if ((arr[i] & (1 << b)) && arr[i] > arr[mxi]) {
                    mxi = i;
                }
            }
            
            if ((arr[mxi] & (1 << b)) == 0) {
                continue;
            }
            
            swap(arr[mxi], arr[ind]);
            
            for (int i = 0; i < n; i++) {
                if (i == ind) {
                    continue;
                }
                
                if ((arr[i] & (1 << b))) {
                    arr[i] ^= arr[ind];
                }
            }
            ind++;
        }
        
        int xr = 0;
        for (const auto&i: arr) {
            xr ^= i;
        }
        
        return xr;
    }
};