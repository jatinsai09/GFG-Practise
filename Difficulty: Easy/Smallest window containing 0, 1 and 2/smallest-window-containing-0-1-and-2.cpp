class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.size(), res = n + 1, d = 0;
        vector<int> f(3);
        for (int l = 0, r = 0; r < n; r++) {
            if (++f[s[r] - '0'] == 1) {
                d++;
            }
            
            while (d == 3) {
                res = min(res, r - l + 1);
                if (--f[s[l] - '0'] == 0) {
                    d--;
                }
                l++;
            }
        }
        
        return res == n + 1 ? -1 : res;
    }
};
