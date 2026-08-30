class Solution {
#define ll long long int
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n < k) {
            return -1;
        }
        
        ll l = 0, r = 0, m;
        for (const auto& i: arr) {
            l = max(l, 1LL * i);
            r += i;
        }
        
        while (l <= r) {
            m = l + (r - l) / 2;
            
            ll s = 0, got = 1;
            for (const auto &i: arr) {
                s += i;
                if (s > m) {
                    got++;
                    s = i;
                }
            }
            
            if (got > k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l;
    }
};