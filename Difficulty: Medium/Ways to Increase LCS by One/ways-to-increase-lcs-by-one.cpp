class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dpl(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1[i] == s2[j]) {
                    dpl[i + 1][j + 1] = dpl[i][j] + 1;
                } else {
                    dpl[i + 1][j + 1] = max(dpl[i + 1][j], dpl[i][j + 1]);
                }
            }
        }
        
        vector<vector<int>> dpr(n1 + 1, vector<int>(n2 + 1));
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dpr[i][j] = dpr[i + 1][j + 1] + 1;
                } else {
                    dpr[i][j] = max(dpr[i + 1][j], dpr[i][j + 1]);
                }
            }
        }
        
        vector<vector<int>> insert(n1 + 1, vector<int>(26));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (dpl[i][j] + dpr[i][j + 1] == dpl[n1][n2]) {
                    insert[i][s2[j] - 'a'] = 1;
                }
            }
        }
        
        int res = 0;
        for (auto &v: insert) {
            res += accumulate(begin(v), end(v), 0LL);
        }
        
        return res;
    }
};
