class Solution {
  public:
    int minCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> prev(n + 1, vector<int>(n + 1, INT_MIN));
        
        prev[0][0] = 0;
        for (int k = 1; k <= n; k++) {
            vector<vector<int>> cur = prev;
            
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (prev[i][j] == INT_MIN) {
                        continue;
                    }
                    
                    if (i == 0 || arr[i - 1] < arr[k - 1]) {
                        cur[k][j] = max(cur[k][j], prev[i][j] + 1);
                    }
                    if (j == 0 || arr[j - 1] > arr[k - 1]) {
                        cur[i][k] = max(cur[i][k], prev[i][j] + 1);
                    }
                }
            }
            
            prev = cur;
        }
        
        int res = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                res = max(res, prev[i][j]);
            }
        }
        return n - res;
    }
};