class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(begin(arr), end(arr));
        int n = arr.size(), res = arr[n - 1] - arr[0];
        
        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0) {
                continue;
            }
            int mn = min(arr[0] + k, arr[i] - k);
            int mx = max(arr[i - 1] + k, arr[n - 1] - k);
            res = min(res, mx - mn);
        }
        return res;
    }
};