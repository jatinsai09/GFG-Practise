class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // code here
        sort(begin(arr), end(arr), [&](auto& a, auto& b){
            return a[0] < b[0];
        });
        
        int r = 0, prev = 0;
        for (auto it : arr) {
            r = max(r, it[0] - prev - 1);
            prev = it[0];
        }
        r = max(r, n - prev);
        
        sort(begin(arr), end(arr), [&](auto& a, auto& b){
            return a[1] < b[1];
        });
        
        int c = 0;
        prev = 0;
        for (auto it : arr) {
            c = max(c, it[1] - prev - 1);
            prev = it[1];
        }
        c = max(c, m - prev);
        
        return r * c;
    }
};