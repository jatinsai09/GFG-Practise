class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(begin(stalls), end(stalls));
        int n = stalls.size(), mx = stalls[n - 1] - stalls[0];
        
        int m, l = 1, r = mx;
        while (l <= r) {
            m = l + (r - l) / 2;
            int prev = stalls[0], c = 1;
            for (int i = 1; i < n; i++) {
                if (stalls[i] - prev >= m) {
                    c++;
                    prev = stalls[i];
                }
            }
            
            if (c >= k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return r;
    }
};