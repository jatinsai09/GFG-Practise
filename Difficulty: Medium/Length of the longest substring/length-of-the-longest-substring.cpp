class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        int n = s.size(), res = 0;
        vector<int> last(26, -1);
        
        for (int l = 0, r = 0; r < n; r++) {
            int c = s[r] - 'a';
            
            if (last[c] >= l) {
                l = last[c] + 1;
            }
            last[c] = r;
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};