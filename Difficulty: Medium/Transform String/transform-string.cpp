class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        if (n != m) {
            return -1;
        }
        
        int f[256] = {0};
        for (int i = 0; i < n; i++) {
            f[s1[i]]++;
            f[s2[i]]--;
        }
        
        for (int i = 0; i < 256; i++) {
            if (f[i]) {
                return -1;
            }
        }
        
        int i = n - 1, j = n - 1, res = 0;
        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                i--;
                res++;
            }
        }
        
        return res;
    }
};
