class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int> f(26);
        for (auto &c: s) {
            f[c - 'a']++;
        }
        
        int odd_count = 0;
        for (auto &i: f) {
            odd_count += (i & 1);
        }
        
        return odd_count < 2;
    }
};