// User function Template for C++

class Solution {
  public:
    vector<int> optimalArray(int n, vector<int> &a) {
        // Code here
        vector<int> res(n), pre(n);
        
        pre[0] = a[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }
        
        int m, left, right;
        for (int i = 1; i < n; i++) {
            m = i / 2;
            
            left = a[m] * (m + 1) - pre[m];
            right = (pre[i] - pre[m]) - a[m] * (i - m);
            
            res[i] = left + right;
        }
        
        return res;
    }
};