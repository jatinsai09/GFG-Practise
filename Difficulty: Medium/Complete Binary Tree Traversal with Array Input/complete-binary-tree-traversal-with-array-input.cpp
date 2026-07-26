class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> res;
        
        int cur = 1;
        for (int i = 0; i < n; i++, cur <<= 1) {
            int j = min(n, i + cur);
            if (i == j) {
                break;
            }
            
            vector<int> v;
            for (int k = i; k < j; k++) {
                v.push_back(arr[k]);
            }
            
            sort(begin(v), end(v));
            res.push_back(v);
            
            
            i = j - 1;
        }
        
        return res;
    }
};
