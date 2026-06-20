class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        int ld = a.back() - '0';
        
        vector<vector<int>> c = {
            {0},
            {1},
            {2, 4, 8, 6},
            {3, 9, 7, 1},
            {4, 6},
            {5},
            {6},
            {7, 9, 3, 1},
            {8, 4, 2, 6},
            {9, 1}
        };
        
        
        int clen = c[ld].size(), mod = 0;
        
        for (auto &c: b) {
            mod = (mod * 10 + (c - '0')) % clen;
        }
        if (mod == 0) {
            mod = clen;
        }
        
        return c[ld][mod - 1];
    }
};