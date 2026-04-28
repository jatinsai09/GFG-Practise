class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size(), res = 1;
        vector<int> f(26);
        for (int l = 0, r = 0; r < n; r++) {
            f[s[r] - 'A']++;
            
            int mx = 0;
            for (auto &i: f) {
                mx = max(mx, i);
            }
            
            int len = r - l + 1;
            if (len - mx <= k) {
                res = max(res, len);
            } else {
                f[s[l++] - 'A']--;
            }
        }
        return res;
    }
};