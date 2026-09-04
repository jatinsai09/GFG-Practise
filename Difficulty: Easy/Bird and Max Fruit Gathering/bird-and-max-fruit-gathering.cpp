class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size(), res = 0, cur = 0;
        
        for (int i = 0; i < n * 2; i++) {
            cur += arr[i % n];
            if (i >= m) {
                cur -= arr[(i - m) % n];
            }
            
            if (i >= m - 1) {
                res = max(res, cur);
            }
        }
        
        return res;
    }
};