class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        int l = 0, r = 0, u = 0, d = 0;
        int x = 0, y = 0;
        for (auto &c: s) {
            if (c == 'L') {
                x--;
            } else if (c == 'R') {
                x++;
            } else if (c == 'U') {
                y--;
            } else {
                y++;
            }
            
            l = min(l, x);
            r = max(r, x);
            
            u = min(u, y);
            d = max(d, y);
        }
        
        return (d - u + 1) <= n && (r - l + 1) <= m;
    }
};