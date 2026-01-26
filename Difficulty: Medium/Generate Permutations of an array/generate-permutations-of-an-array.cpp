class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> res;
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                res.push_back(arr);
                return;
            }
            
            for (int j = i; j < n; j++) {
                swap(arr[i], arr[j]);
                dfs(i + 1);
                swap(arr[i], arr[j]);
            }
        };
        
        dfs(0);
        return res;
    }
};