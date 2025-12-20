class Solution {
  public:
     bool isSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }
    int minSquares(int n) {
        // Code here
        if (isSquare(n)) {
            return 1;
        }
        
        for (int i = 1; i * i <= n; i++) {
            int rem = n - i * i;
            if (isSquare(rem)) {
                return 2;
            }
        }

        while (n % 4 == 0) {
            n /= 4;
        }

        return (n % 8 == 7 ? 4 : 3);
    }
};