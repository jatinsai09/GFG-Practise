class Solution {
  public:
    int validGroups(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(901, -1));
        
        function<int(int, int)> f = [&](int i, int prev) -> int {
          if (i == n) {
              return 1;
          }  
          
          if (dp[i][prev] != -1) {
              return dp[i][prev];
          }
          
          int res = 0, cur = 0;
          
          for (int e = i; e < n; e++) {
              cur += (s[e] - '0');
              
              if (cur >= prev) {
                  res += f(e + 1, cur);
              }
          }
          
          return dp[i][prev] = res;
        };
        
        return f(0, 0);
    }
};