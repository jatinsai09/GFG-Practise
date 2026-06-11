class Solution {
  public:
    int findIndex(string &s) {
        // code here
        
        int n = s.size(), cl = 0;
        for (auto &c: s) {
            cl += (c == ')');
        }
        
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (op == cl) {
                return i;
            }
            
            if (s[i] == ')') {
                cl--;
            } else {
                op++;
            }
        }
        
        if (op == cl) {
            return n;
        }
    }
};