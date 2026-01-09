class Solution {
  public:
    int waysToIncreaseLCSBy1(int n, string S1, int m, string S2) {
        // code here
        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

        // Prefix LCS
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(S1[i - 1] == S2[j - 1]){
                    dp1[i][j] = 1 + dp1[i - 1][j - 1];
                } else {
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
                }
            }
        }
        int L = dp1[n][m];

        // Suffix LCS
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(S1[i] == S2[j]){
                    dp2[i][j] = 1 + dp2[i + 1][j + 1];
                } else {
                    dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
                }
            }
        }

        int res = 0;
        for(int i = 0; i <= n; i++){
            vector<bool> used(26, false);
            for(int j = 0; j < m; j++){
                if(dp1[i][j] + dp2[i][j + 1] == L){
                    int c = S2[j] - 'a';
                    if(!used[c]){
                        used[c] = true;
                        res++;
                    }
                }
            }
        }

        return res;
    }
};
