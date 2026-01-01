class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int mx = 0;
        for(auto &ivl: arr) {
            mx = max(mx, ivl[1]);
        }

        vector<int> d(mx + 2, 0);
        for(auto& ivl: arr) {
            d[ivl[0]]++;
            d[ivl[1] + 1]--;
        }

        int cur = 0, res = 0;
        for(int i = 0; i <= mx; i++) {
            cur += d[i];
            res = max(res, cur);
        }
        return res;
    }
};
