class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        if (n == 1) {
            return k;
        }
        vector<int> dp1(n), dp2(n);
        dp1[0] = dp2[0] = k;
        dp1[1] = k * (k - 1);
        dp2[1] = k;
        
        for (int i = 2; i < n; i++) {
            dp1[i] = (k - 1) * (dp1[i - 1] + dp2[i - 1]);
            dp2[i] = dp1[i - 1];
        }
        
        return dp1[n - 1] + dp2[n - 1];
    }
};