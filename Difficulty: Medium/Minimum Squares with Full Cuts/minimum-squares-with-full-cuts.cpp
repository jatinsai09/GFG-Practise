class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        if (n == m) {
            return 1;
        }
        if (n > m) {
            swap(n, m);
        }
        
        if (m % n == 0) {
            return m / n;
        }
        
        return 1 + minSquares(n, m - n);
    }
};