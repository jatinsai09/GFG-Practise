class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();
        if (n == 1) {
            return (s[0] == '1');
        }
        
        int st = 0;
        while (st < n && s[st] != '1') {
            st++;
        }
        
        if (st > x || st == n) {
            return false;
        }
        
        int prev = st;
        
        for (int i = st + 1; i < n; i++) {
            if (s[i] == '1') {
                if (i - prev - 1 > 2 * x) {
                    return false;
                }
                prev = i;
            }
        }
        
        return n - prev - 1 <= x;
    }
};