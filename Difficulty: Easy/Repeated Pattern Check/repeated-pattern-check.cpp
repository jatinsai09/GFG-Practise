class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int n = s.size(), xc = 0, yc = 0;
        
        for (int i = 0; i < n; i++) {
            (s[i] == 'x' ? xc++ : yc++);
            
            if (i == n - 1 || s[i] == 'y' && s[i + 1] == 'x') {
                if (xc != yc) {
                    return false;
                }
                xc = yc = 0;
            }
        }
        return true;
    }
};