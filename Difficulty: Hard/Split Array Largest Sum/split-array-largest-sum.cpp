class Solution {
  public:
    bool ok(vector<int>& a, int k, long long m) {
        long long s = 0;
        int c = 1, n = a.size();
        for(int i = 0; i < n; i++) {
            if(s + a[i] <= m) {
                s += a[i];
            } else {
                s = a[i];
                c++;
            }
        }
        return c <= k;
    }
    int splitArray(vector<int>& a, int k) {
        // code here
        int n = a.size();
        long long l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            l = max(l, (long long)a[i]);
            r += a[i];
        }
        
        while(l <= r) {
            long long m = (l + r) / 2;
            
            if(ok(a, k, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};