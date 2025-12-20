class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n = arr.size(), l = 0, r = n - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (arr[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return r;
    }
};
