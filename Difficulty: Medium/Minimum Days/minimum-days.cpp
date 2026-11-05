class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int n = s.size(), res = 0;
        
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            t[p[i]] = i + 1;
        }
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                res = max(res, min(t[i], t[i - 1]));
            }
        }
        
        return res;
    }
};
