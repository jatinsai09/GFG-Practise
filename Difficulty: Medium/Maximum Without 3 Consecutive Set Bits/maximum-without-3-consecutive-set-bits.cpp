class Solution {
  public:
    int maxValue(int n) {
        // code here
        int res = 0, b = 31, c = 0;
        
        while (b >= 0) {
            if ((n >> b) & 1) {
                c++;
            } else {
                c = 0;
            }
            
            if (c == 3) {
                c = 0;
                n -= (1 << b);
            }
            
            
            
            b--;
        }
        
        return n;
    }
};