class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (pat[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = false;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (txt[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pat[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; 
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};