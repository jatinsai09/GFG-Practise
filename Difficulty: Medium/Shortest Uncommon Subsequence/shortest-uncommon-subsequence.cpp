class Solution {
  public:
    int shortestUnSub(string S, string T) {
        // code here
        int n = S.size(), m = T.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
        for(int i = 0; i < n; i++){
            dp[i][m] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int op1 = dp[i + 1][j];

                int k = j;
                while(k < m && T[k] != S[i]){
                    k++;
                }

                int op2;
                if(k == m){
                    op2 = 1;
                } else {
                    op2 = 1 + dp[i + 1][k + 1];
                }

                dp[i][j] = min(op1, op2);
            }
        }

        if(dp[0][0] >= INF){
            return -1;
        }
        return dp[0][0];
    }
};