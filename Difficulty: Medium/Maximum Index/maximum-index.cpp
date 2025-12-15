class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> lmin(n), rmax(n);
        
        lmin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            lmin[i] = min(lmin[i - 1], arr[i]);
        }
        
        rmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], arr[i]);
        }
        
        int res = 0, i = 0, j = 0;
        while (j < n) {
            if (lmin[i] <= rmax[j]) {
                res = max(res, j - i);
            } else {
                i++;
            }
            j++;
        }
        
        return res;
    }
};