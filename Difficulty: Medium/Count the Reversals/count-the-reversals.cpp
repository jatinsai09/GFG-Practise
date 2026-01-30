class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        int n = s.size();
        if (n & 1) {
            return -1;
        }
        int op = 0, cl = 0;
        for (auto &c: s) {
            if (c == '{') {
                op++;
            } else {
                if (op) {
                    op--;
                } else {
                    cl++;
                }
            }
        }
        
        return (op + 1) / 2 + (cl + 1) / 2;
    }
};