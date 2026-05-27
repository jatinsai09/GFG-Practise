class Solution {
  public:
    string getLongestPal(string &s) {
        // code here
        int n = s.size();
        int start = 0, maxLen = 1;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                int l = i, r = i + j; 
    
                while (l >= 0 && r < n && s[l] == s[r]) 
                {
                    int curLen = r - l + 1;
                    if (curLen > maxLen) {
                        start = l;
                        maxLen = curLen;
                    }
                    l--;
                    r++;
                }
            }
        }
    
        return s.substr(start, maxLen);
    }
};