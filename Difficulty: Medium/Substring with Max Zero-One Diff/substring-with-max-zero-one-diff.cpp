class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int n = s.size(), res = -1, cur = 0;
        
        for (auto &c: s) {
            cur += (c == '1' ? -1 : 1);
            res = max(res, cur);
            cur = max(cur, 0);
        }
        
        return res;
    }
};