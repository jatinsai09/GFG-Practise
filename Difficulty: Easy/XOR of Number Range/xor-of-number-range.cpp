class Solution {
  public:
    int xorTillN(int n) {
        int res = 0;
        for(int b = 0; b < 31 && (1LL << b) <= n; b++){
    
            int cyc = (1LL << (b + 1));
    
            int full_cyc = (n / cyc), r = n % cyc;
    
            int lst = max(0LL, r - (1LL << b) + 1);
    
            int cur = full_cyc * (1LL << b) + lst;
    
            res |= (1LL << b) * (cur & 1);
        }
        
        return res;
    }
    int findXOR(int l, int r) {
        // code here
        
        return xorTillN(r) ^ xorTillN(l - 1);
    }
};