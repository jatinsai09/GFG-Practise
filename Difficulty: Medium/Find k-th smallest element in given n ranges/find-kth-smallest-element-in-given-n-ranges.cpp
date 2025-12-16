// User function Template for C++

class Solution {
#define ll long long int    
  public:
    vector<int> kthSmallestNum(int n, vector<vector<int>>& range, int q,
                               vector<int> queries) {
        // Write your code here
        sort(begin(range), end(range));
        vector<pair<int, int>> v;
        int l = range[0][0], r = range[0][1];
        
        for (int i = 1; i < n; i++) {
            if (range[i][0] <= r + 1) {
                r = max(r, range[i][1]);
            } else {
                v.push_back({l, r});
                l = range[i][0];
                r = range[i][1];
            }
        }
        v.push_back({l, r});
        int m = v.size();
        
        vector<int> res;
        for (auto &q: queries) {
            int k = q, val = -1;
            
            for (int i = 0; i < m; i++) {
                int l = v[i].first, r = v[i].second;
                
                if (k <= (r - l + 1)) {
                    val = l + (k - 1);
                    break;
                }
                
                k -= (r - l + 1);
            }
            
            res.push_back(val);
        }
        
        return res;
    }
};
