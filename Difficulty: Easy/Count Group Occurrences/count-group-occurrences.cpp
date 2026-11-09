class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        int n = s.size(), res = 0;
        vector<int> f(26);
        
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            f[s[j - 1] - 'a']++;
            
            i = j;
        }
        
        for (auto &i: f) {
            res += (i == k);
        }
        return res;
    }
};