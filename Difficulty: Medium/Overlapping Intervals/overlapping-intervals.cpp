class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(begin(arr), end(arr));
        vector<vector<int>> res;
        
        vector<int> p = arr[0];
        
        for (int i = 1; i < n; i++) {
            if (p[1] < arr[i][0]) {
                res.push_back(p);
                p = arr[i];
            } else {
                p[1] = max(p[1], arr[i][1]);
            }
        }
        res.push_back(p);
        
        return res;
    }
};