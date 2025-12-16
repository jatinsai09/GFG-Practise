class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.size(), res = 0, unq = 0;
        int f[26] = {0};
        
        for (int i = 0; i < n; i++) {
            unq += (++f[s[i] - 'a'] == 1);
            if (i >= k) {
                unq -= (--f[s[i - k] - 'a'] == 0);
            }
            
            res += (i + 1 >= k && unq == k - 1);
        }
        
        return res;
    }
};