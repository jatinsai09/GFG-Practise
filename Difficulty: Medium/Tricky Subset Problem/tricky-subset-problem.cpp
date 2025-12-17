// User function Template for C++

class Solution {
  public:
    int isPossible(long long s, long long n, long long x, long long a[]) {
        // code here
        vector<long long> v;
        long long p = s;
        v.push_back(s);
        
        for (int i = 0; i < n; i++) {
            long long val = p + a[i];
            v.push_back(val);
            p += val;
            if (p > x) {
                break;
            }
        }
        
        long long m = v.size();
        for (int i = m - 1; i >= 0; i--) {
            if (v[i] <= x) {
                x -= v[i];
            }
        }
        
        return x == 0;
    }
};