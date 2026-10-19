class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0;
        
        vector<int> dp(n, -1), vis(n);
        
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0 || i >= n) {
                return 1;
            }
            if (vis[i]) {
                return (vis[i] == 1 ? 1 : 0);
            }
            
            vis[i] = 2;
            dp[i] = dfs(i + arr[i]);
            vis[i] = (dp[i] == 1 ? 1 : 2);
            
            return dp[i];
        };
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) {
                dfs(i);
            }
            res += dp[i];
        }
        
        return res;
    }
};