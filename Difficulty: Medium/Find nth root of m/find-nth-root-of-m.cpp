class Solution {
  public:
    long long modExp(long long base, int exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1) {
                res = res * base;
            }
            
            base = base * base;
            exp >>= 1;
        }
        
        return res;
    }
    int nthRoot(int n, int m) {
        // Code here
        int l = 0, r = m, mid;
        
        while (l <= r) {
            mid = l + (r - l) / 2;
            
            long long got = modExp(mid, n);
            
            if (got > m) {
                r = mid - 1;
            } else if (got < m) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
};