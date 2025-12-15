// User function Template for C++

class Solution {
  public:
    vector<int> updateQuery(int n, int q, vector<vector<int>> &U) {
        // code here
        vector<int> res(n);
        vector<vector<int>> dp(n + 2, vector<int>(32));
        
        for (auto &v: U) {
            int l = v[0] - 1, r = v[1] - 1, x = v[2];
            
            for (int i = 0; i < 32; i++) {
                if ((x >> i) & 1) {
                    dp[l][i]++;
                    dp[r + 1][i]--;
                }
            }
        }
        
        
        for (int j = 0; j < 32; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                cur += dp[i][j];
                res[i] += (1 << j) * (cur > 0);
            }
        }
        
        return res;
    }
};