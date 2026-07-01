class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size(), res = INT_MIN, s = 0;
        if (n == 1) {
            return arr[0];
        }
        
        for (auto &i: arr) {
            s = max(s + i, i);
            res = max(res, s);
        } 
        
        vector<int> suf(n + 1);
        suf[n - 1] = arr[n - 1];
        s = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s = max(s + arr[i], arr[i]);
            suf[i] = s;
        }
        
        s = arr[0];
        for (int i = 1; i + 1 < n; i++) {
            res = max(res, s + suf[i + 1]);
            s = max(s + arr[i], arr[i]);
        }
        
        return res;
    }
};