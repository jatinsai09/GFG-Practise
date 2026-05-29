class Solution {
  public:
    int maxProductSum(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        long p = 0;
        for (int i = 0; i < n; i++) {
            p += a[i] * b[i];
        }
        return p;
    }
};