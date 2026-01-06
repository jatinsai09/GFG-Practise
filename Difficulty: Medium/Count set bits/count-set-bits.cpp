class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int res = 0;
        for (int b = 0; (1 << b) <= n; b++) {
            int cycle = 1 << (b + 1);
            
            int full = (n + 1) / cycle;
            res += full * (1 << b);
            
            int rem = (n + 1) % cycle;
            if (rem > (1 << b)) {
                res += rem - (1 << b);
            }
        }
        
        return res;
    }
};
