class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        int m = a.size();
        vector<int> res(n + 1, 0);
        
        for (int i = 0; i < m; i++) {
            int l = a[i], r = b[i], inc = k[i];
            
            res[l] += inc;
            res[r + 1] -= inc;
        }
        
        int mx = res[0];
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
            mx = max(mx, res[i]);
        }
        
        return mx;
    }
};