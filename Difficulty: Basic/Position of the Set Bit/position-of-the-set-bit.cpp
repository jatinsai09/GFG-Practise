class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n & (n - 1)) {
            return -1;
        }
        
        int p = 0;
        while (n) {
            p++;
            n >>= 1;
        }
        
        return p;
    }
};