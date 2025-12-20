class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), l = 0, r = n - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == k) {
                return m;
            }
            
            if (arr[m] > k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
};