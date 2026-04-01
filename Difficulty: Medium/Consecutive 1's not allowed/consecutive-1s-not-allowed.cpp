class Solution {
  public:
    int countStrings(int n) {
        // code here
        vector<int> dp0(n + 1), dp1(n + 1);
        dp0[1] = dp1[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp1[i] = dp0[i - 1];
            dp0[i] = dp0[i - 1] + dp1[i - 1];
        }
        
        return dp1[n] + dp0[n];
    }
};