
class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // code here
        vector<int> dp(n + 1);
        
        int c = 0;
        while(dp[n] < k){
            c++;
            for(int i = n; i > 0;i--){
                dp[i] += 1 + dp[i-1];  
            }
        }
        return c;
        
    }
};

