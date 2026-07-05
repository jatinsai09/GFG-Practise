class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n = s.size(), res = -1;
        vector<int> fi(26, n);
        
        for (int i = 0; i < n; i++) {
            res = max(res, i - fi[s[i] - 'a'] - 1);
            
            fi[s[i] - 'a'] = min(fi[s[i] - 'a'], i);
        }
        
        return res;
    }
};