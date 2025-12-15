class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        sort(begin(arr), end(arr));
        int n = arr.size();
        int l = 0, r = n - 1, mul = arr[n - 1] + 1;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr[i] += (arr[r--] % mul) * mul;
            } else {
                arr[i] += (arr[l++] % mul) * mul;
            }
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] /= mul;
        }
    }
};