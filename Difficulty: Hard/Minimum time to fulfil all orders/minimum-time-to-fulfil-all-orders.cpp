class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        // code here
        int mn = INT_MAX;
        for (auto &rank: ranks) {
            mn = min(mn, rank);
        }
        
        long long t, l = 0, r = (long long)mn * (n * (n + 1)) / 2;
        while (l <= r) {
            t = l + (r - l) / 2;
            
            long long got = 0;
            for (auto &rank: ranks) {
                long long x = (long long)(sqrt(1 + 8.0 * t / rank) - 1) / 2;
                got += x;
            }
            
            if (got >= n) {
                r = t - 1;
            } else {
                l = t + 1;
            }
        }
        
        return (int)l;
    }
};