class Solution {
  public:
    string countSort(string s) {
        // code here
        int f[26] = {0};
        for (const auto& c: s) {
            f[c - 'a']++;
        }
        
        string res;
        for (int i = 0; i < 26; i++) {
            while (f[i]--) {
                res.push_back(char('a' + i));
            }
        }
        
        return res;
    }
};