class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        vector<bool> dp(k);
        
        for (auto &a: arr) {
            if (a % k == 0) {
                return true;
            }
            
            vector<bool> nxt(dp);
            
            int rem = a % k;
            nxt[rem] = 1;

            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    nxt[(r + rem) % k] = true;
                }
            }
            
            dp = nxt;
        }
        
        return dp[0];
    }
};