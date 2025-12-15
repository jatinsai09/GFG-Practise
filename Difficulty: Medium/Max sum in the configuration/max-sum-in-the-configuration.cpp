class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0, cur = 0,s = 0;
        
        for (int i = 0; i < n; i++) {
            cur += i * arr[i];
            s += arr[i];
        }
        
        res = cur;
        
        for (int i = n - 1; i > 0; i--) {
            cur += s;
            cur -= n * arr[i];
            
            res = max(res, cur);
        }
        
        return res;
    }
};