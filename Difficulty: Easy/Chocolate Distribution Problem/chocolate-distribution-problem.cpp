class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(begin(a), end(a));
        int n = a.size(), mn = a[m - 1] - a[0];
        
        for (int i = m; i < n; i++) {
            mn = min(mn, a[i] - a[i - m + 1]);
        }
        
        return mn;
    }
};