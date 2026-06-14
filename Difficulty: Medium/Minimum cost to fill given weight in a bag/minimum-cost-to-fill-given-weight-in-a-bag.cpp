class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n = cost.size();
        vector<int> dp(w + 1, -1);
        dp[0] = 0;
        
        function<int(int)> f = [&](int wt) -> int {
            if (dp[wt] != -1) {
                return dp[wt];
            } 
            
            int mn = INT_MAX;
            for (int i = 0; i < n && i < wt; i++) {
                if (cost[i] == -1) {
                    continue;
                } 
                int got = f(wt - i - 1);
                if (got != INT_MAX) {
                    mn = min(mn, cost[i] + got);
                }
            }
            
            return dp[wt] = mn;
        };
        
        int res = f(w);
        return res == INT_MAX ? -1 : res;
    }
};
