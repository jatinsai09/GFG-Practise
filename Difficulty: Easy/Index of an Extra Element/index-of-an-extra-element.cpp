class Solution {
  public:
    int findExtra(vector<int>& a, vector<int>& b) {
        // add code here.
        int n = b.size(), l = 0, r = n - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (a[m] == b[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l;
    }
};