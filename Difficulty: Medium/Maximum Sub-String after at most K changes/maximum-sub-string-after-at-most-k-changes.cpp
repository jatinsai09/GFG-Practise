class Solution {
  public:
    int characterReplacement(string s, int k) {
        // Code here
        int n = s.size(), mx = 0, res = 0;
        vector<int> f(26);
        
        for (int l = 0, r = 0; r < n; r++) {
            mx = max(mx, ++f[s[r] - 'A']);
            
            if ((r - l + 1) - mx > k) {
                --f[s[l++] - 'A'];
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};