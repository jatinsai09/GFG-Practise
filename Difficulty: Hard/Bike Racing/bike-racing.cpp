// User function Template for C++

class Solution {
  public:
    long buzzTime(long n, long m, long l, long h[], long a[]) {
        // code here
        int lo = 0, hi = max(m, l), mid;
        
        auto ok = [&](long long t) -> bool {
            long long s = 0;
            
            for(int i = 0; i < n; i++) {
                long long v = h[i] + a[i] * t;
                
                if(v >= l) {
                    s += v;
                    if(s >= m) {
                        return true;
                    }
                }
            }
            
            return false;
        };
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if(ok(mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};