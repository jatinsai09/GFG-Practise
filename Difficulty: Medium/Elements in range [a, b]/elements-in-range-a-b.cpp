class Solution {
  public:
    int lb(vector<int>& a, int x) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (a[m] < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    int ub(vector<int>& a, int x) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (a[m] <= x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int q = queries.size();
        sort(begin(arr), end(arr));

        vector<int> res;
        for (int i = 0; i < q; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            res.push_back(ub(arr, b) - lb(arr, a));
        }

        return res;
    }
};