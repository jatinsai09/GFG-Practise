class Solution {
  public:
    int isPallindrome(long long int n) {
        // code here
        if (n % 2 == 0) {
            return 0;
        }
        
        long long int og = n, rev = 0;
        
        while (n) {
            rev = (rev << 1) | (n & 1);
            n >>= 1;
        }
        
        return rev == og;
    }
};