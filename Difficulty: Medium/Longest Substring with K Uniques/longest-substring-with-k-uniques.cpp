class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        vector<int> cnt(26, 0);
        
        int unq = 0, res = -1;
        for(int l = 0, r = 0; r < n; r++) {
            if(++cnt[s[r] - 'a'] == 1) {
                unq++;
            }
            
            if (unq > k) {
                unq -= (--cnt[s[l++] - 'a'] == 0);
            }
            
            if(unq == k) {
                res = max(res, r - l + 1);
            }
        }
        
        return res;
    }
};