class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        int n = arr.size();
        vector<int> f(high - low + 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] >= low && arr[i] <= high) {
                f[arr[i] - low] = 1;
            }
        }
        
        vector<int> res;
        for (int i = low; i <= high; i++) {
            if (f[i - low] == 0) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};