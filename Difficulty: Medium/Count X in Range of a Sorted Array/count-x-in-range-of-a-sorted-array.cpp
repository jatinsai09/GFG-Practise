class Solution {
  public:
    int first(auto& a, int l, int r, int x) {
        int ind = -1;
        while (l <= r) {
            int m = (l + r) >> 1;
            
            if (a[m] >= x) {
                if (a[m] == x) {
                    ind = m;
                } 
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ind;
    }
    int last(auto& a, int l, int r, int x) {
        int ind = -1;
        while (l <= r) {
            int m = (l + r) >> 1;
            
            if (a[m] <= x) {
                if (a[m] == x) {
                    ind = m;
                }
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ind;
    }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> res;
        int l, r, x;
        for (const auto& q: queries) {
            l = q[0], r = q[1], x = q[2];
            int fi = first(arr, l, r, x), li = last(arr, l, r, x);
            if (fi == -1 && li == -1) {
                res.push_back(0);
            } else {
                res.push_back(li - fi + 1);
            }
        }
        
        return res;
    }
};