// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n = s.size(), res = 0;\
        
        for (int i = 0; i < n; i++) {
            int f[26] = {0}, mx = 0;
            for (int j = i; j < n; j++) {
                mx = max(mx, ++f[s[j] - 'a']);
                
                int mn = 1e9;
                for (int k = 0; k < 26; k++) {
                    if (f[k] > 0) {
                        mn = min(mn, f[k]);
                    }
                }
                
                res += (mx - mn);
            }
        }
        return res;
    }
};