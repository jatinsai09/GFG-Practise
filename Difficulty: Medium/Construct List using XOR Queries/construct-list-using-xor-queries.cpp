class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        int xr = 0;
        vector<int> res = {0};
        
        for (auto &q: queries) {
            if (!q[0]) {
                res.push_back(q[1] ^ xr);
            } else {
                xr ^= q[1];
            }
        }
        for (auto &it: res) {
            it ^= xr;
        }
        sort(begin(res), end(res));
        return res;
    }
};
