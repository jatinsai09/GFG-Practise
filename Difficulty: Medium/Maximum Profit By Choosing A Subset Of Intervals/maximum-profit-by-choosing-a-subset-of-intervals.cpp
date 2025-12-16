// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &ivls) {
        // Write your code here.
        sort(begin(ivls), end(ivls), [&](auto& x, auto& y){
            return x[1] < y[1];
        });
        
        vector<int> dp(n), et(n);
        for (int i = 0; i < n; i++) {
            et[i] = ivls[i][1];
        }
        
        dp[0] = ivls[0][2];
        for (int i = 1; i < n; i++) {
            int pick = ivls[i][2];
            
            int l = 0, r = i - 1, ind = -1, m;
            while (l <= r) {
                m = l + (r - l) / 2;
                if (et[m] <= ivls[i][0]) {
                    ind = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
            if (ind != -1) {
                pick += dp[ind];
            }
            
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        
        return dp[n - 1];
    }
};