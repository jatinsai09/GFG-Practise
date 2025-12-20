class Solution {
  public:
    int transitionPoint(vector<int>& a) {
        // code here
        int n = a.size(), l = 0, r = n - 1;
        if (a[n - 1] == 0) {
            return -1;
        }
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (a[m] == 1) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
};