class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        long long mx = *max_element(begin(arr), end(arr));
        long long l = 1, r = mx, m;
        
        auto can = [&](long long m) -> bool {
            long long cur = m;
            for (auto &i: arr) {
                if (cur >= mx) {
                    return true;
                }
                cur = cur * 2 - i;
                if (cur < 0) {
                    return false;
                }
            }
            
            return true;
        };
        
        while (l <= r) {
            m = l + (r - l) / 2;
            
            if (can(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
};