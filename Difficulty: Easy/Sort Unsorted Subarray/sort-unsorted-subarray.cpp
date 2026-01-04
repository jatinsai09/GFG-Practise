// User function template for C++
class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
        // Code here
        int n = arr.size(), l = 0, r = n - 1;
        
        while (l + 1 < n && arr[l + 1] >= arr[l]) {
            l++;
        }
        
        if (l == n) {
            return {0, 0};
        }
        
        while (r - 1 >= 0 && arr[r - 1] <= arr[r]) {
            r--;
        }
        
        int mn = arr[l], mx = arr[l];
        for (int i = l; i <= r; i++) {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
        
        while (l - 1 >= 0 && arr[l - 1] > mn) {
            l--;
        }
        while (r + 1 < n && arr[r + 1] < mx) {
            r++;
        }
        
        return {l, r};
    }
};