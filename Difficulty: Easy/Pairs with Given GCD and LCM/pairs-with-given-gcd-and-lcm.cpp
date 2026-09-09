class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        if (y % x) {
            return 0;
        }
        
        int n = y / x, res = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;
                
                if (__gcd(i, j) == 1) {
                    res++;
                    res += (i != j);
                }
            }
        }
        
        return res;
    }
};