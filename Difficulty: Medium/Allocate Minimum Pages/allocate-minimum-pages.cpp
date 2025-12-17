class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n < k) {
            return -1;
        }
        
        int l = *max_element(begin(arr), end(arr));
        int r = accumulate(begin(arr), end(arr), 0), m;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            
            int s = 0, g = 1;
            for (auto &i: arr) {
                if (s + i > m) {
                    g++;
                    s = i;
                } else {
                    s += i;
                }
            }
            
            if (g > k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l;
    }
};