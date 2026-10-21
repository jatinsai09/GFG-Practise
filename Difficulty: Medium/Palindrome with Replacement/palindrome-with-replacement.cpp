class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '?' || s[n - i - 1] == '?') {
                continue;
            }
            
            if (s[i] != s[n - i - 1]) {
                return -1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (s[n - i - 1] != '?') {
                    s[i] = s[n - i - 1];
                }
            }
        }
        
        int prev = -1, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                continue;
            }
            if (prev != -1) {
                res += abs((s[i] - 'a') - prev);
            }
            prev = s[i] - 'a';
        }
        
        return res;
    }
};