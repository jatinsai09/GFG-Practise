class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int s = 0, mx = 0;
        for (const auto& i: arr) {
            s += i;
            mx = max(mx, i);
        }
        
        auto can = [&](int m) -> bool {
            int need = 1, cur = 0;
            for (const auto &i: arr) {
                if (cur + i > m) {
                    cur = i;
                    need++;
                } else {
                    cur += i;
                }
                
                if (need > k) {
                    return false;
                }
            }
            
            return true;
        };
        
        int l = mx, r = s, m;
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