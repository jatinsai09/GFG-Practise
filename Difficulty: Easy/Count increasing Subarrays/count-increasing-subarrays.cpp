class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        
        int n = arr.size(), res = 0;
        
        for (int l = 0, r = 1; r < n; r++) {
            if (arr[r] <= arr[r - 1]) {
                l = r;
            } else {
                res += r - l;
            }
        }
        
        return res;
    }
};
