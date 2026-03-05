class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        vector<int> cnt(26, 0);
        
        int dist = 0, res = -1;
        for(int l = 0, r = 0; r < n; r++) {
            if(++cnt[s[r] - 'a'] == 1) {
                dist++;
            }
            
            while (dist > k) {
                if(--cnt[s[l++] - 'a'] == 0) {
                    dist--;
                }
            }
            
            if(dist == k) {
                res = max(res, r - l + 1);
            }
        }
        
        return res;
    }
};