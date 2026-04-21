class Solution {
  public:
    int f(int from, int to, int d) {
        int a = from, b = 0, steps = 1;
        
        while (a != d && b != d) {
            int t = min(a, to - b);
            a -= t;
            b += t;
            steps++;
            
            if (a == d || b == d) {
                break;
            }
            
            if (a == 0) {
                a = from;
                steps++;
            }
            
            if (b == to) {
                b = 0;
                steps++;
            }
        }
        
        return steps;
    }
    int minSteps(int m, int n, int d) {
        // Code here
        if (d > max(m, n)) {
            return -1;
        }
        if (d % __gcd(m, n)) {
            return -1;
        }
        
        return min(f(m, n, d), f(n, m, d));
    }
};