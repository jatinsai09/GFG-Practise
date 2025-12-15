class Solution {
  public:
    vector<int> findRange(string s, int n) {
        // code here
        int l = 0, cur = 0, mx = 0, bl = -1, br = -1;
        
        for (int i = 0; i < n; i++) {
            int val = (s[i] == '1' ? -1 : 1);
            
            if (cur + val < val) {
                cur = val;
                l = i;
            } else {
                cur += val;
            }
            
            if (cur > mx) {
                bl = l;
                br = i;
                mx = cur;
            }
        } 
        
        if (mx == 0) {
            return {-1};
        }
        
        return {bl + 1, br + 1};
    }
};