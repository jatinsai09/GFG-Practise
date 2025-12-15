// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int n = a.size(), s = a[0], res = a[0];
        
        for (int i = 1; i < n; i++) {
            s = min(s + a[i], a[i]);
            res = min(res, s);
        }
        return res;
    }
};
