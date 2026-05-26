
class Solution {
  public:
    bool equalPartition(vector<int>& a) {
        // code here
        int n = a.size(), sum = 0;
        for(auto& i: a){
            sum += i;
        }
        if(sum & 1){
            return false;
        }
        
        int req = sum >> 1;
        vector<vector<bool>> dp(n + 1, vector<bool>(req + 1, false));
        for(int i = 0; i <= n; i++){
            dp[i][0]=true;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= req; j++){
                if(a[i - 1] <= j){
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][req];
    }
};

