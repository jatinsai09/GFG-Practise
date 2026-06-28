class Solution {
  public:
    int countStrings(int n, int k) {
        // code here
        const int mod = 1e9 + 7;
        
        vector<int> dp1(k + 1), dp0(k + 1);
        
        dp0[0] = dp1[0] = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> ndp1(k + 1), ndp0(k + 1);
            for (int j = 0; j <= min(i - 1, k); j++) {
                ndp1[j] = ((j ? dp1[j - 1] : 0) + dp0[j]) % mod;
                ndp0[j] = (dp1[j] + dp0[j]) % mod;
            }
            dp0 = ndp0;
            dp1 = ndp1;
        }
        
        return (dp0[k] + dp1[k]) % mod;
    }
};