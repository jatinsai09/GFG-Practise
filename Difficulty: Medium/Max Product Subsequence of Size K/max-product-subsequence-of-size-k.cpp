class Solution {
#define ll long long int
const ll INF = 4e18;
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        
        ll n = arr.size();
        vector<vector<ll>> mx(n + 1, vector<ll>(k + 1, -INF));
        vector<vector<ll>> mn(n + 1, vector<ll>(k + 1, INF));
        
        mx[0][0] = mn[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
                mn[i][j] = mn[i - 1][j];
                mx[i][j] = mx[i - 1][j];
                
                if (j) {
                    if (mn[i - 1][j - 1] != INF) {
                        mn[i][j] = min(mn[i][j], 
                                    arr[i - 1] * mn[i - 1][j - 1]);
                                    
                        mx[i][j] = max(mx[i][j],
                                    arr[i - 1] * mn[i - 1][j - 1]);
                    }
                    
                    if (mx[i - 1][j - 1] != -INF) {
                        mn[i][j] = min(mn[i][j],
                                    arr[i - 1] * mx[i - 1][j - 1]);
                                    
                        mx[i][j] = max(mx[i][j],
                                    arr[i - 1] * mx[i - 1][j - 1]);
                        
                    }
                }
            }
        }
        
        return mx[n][k];
    }
};