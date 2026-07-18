class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        
        vector<int> ls(n, 0), rg(n, n - 1);
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] < arr[i]) {
                ls[i] = i;
            } else {
                ls[i] = ls[i - 1];
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                rg[i] = i;
            } else {
                rg[i] = rg[i + 1];
            }
        }
        
        vector<bool> res;
        for (auto &q: queries) {
            int l = q[0], r = q[1];
            if (ls[r] <= rg[l]) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
            //cout << ls[r] << " " << rg[l] << "\n";
        }
        return res;
    }
};