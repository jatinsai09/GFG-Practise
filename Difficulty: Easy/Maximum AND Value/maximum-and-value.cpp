class Solution {
  public:
    int findMaxAnd(vector<int>& arr) {
        // code here
        int n = arr.size(), res = 0;
        
        for (int i = 19; i >= 0; i--) {
            int msk = res | (1 << i), c = 0;
            
            for (auto &x: arr) {
                if ((x & msk) == msk) {
                    c++;
                }
            }
            
            if (c >= 2) {
                res = msk;
            }
        }
        
        return res;
    }
};
