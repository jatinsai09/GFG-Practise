// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int k = __builtin_popcount(b), x = 0;
    
        for(int i = 31; i >= 0 && k > 0; i--) {
            if(a & (1 << i)) {
                x |= (1 << i);
                k--;
            }
        }
    
        for(int i = 0; i <= 31 && k > 0; i++) {
            if(!(x & (1 << i))) {
                x |= (1 << i);
                k--;
            }
        }
    
        return x;
    }
};