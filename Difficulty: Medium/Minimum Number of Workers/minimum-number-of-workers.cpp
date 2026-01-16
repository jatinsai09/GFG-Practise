class Solution {
  public:
    int minMen(vector<int>& a) {
        // code here
        int n = a.size();
        vector<pair<int,int>> v;
    
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                int l = max(0, i - a[i]);
                int r = min(n - 1, i + a[i]);
                v.push_back({l, r});
            }
        }
        
        int m = v.size();
        sort(begin(v), end(v));
        
        int i = 0, pos = 0, res = 0;
        while (pos < n) {
            int mx = pos - 1;
            while (i < m && v[i].first <= pos) {
                mx = max(mx, v[i].second);
                i++;
            }
            
            if (mx < pos) {
                return -1;
            }
            
            pos = mx + 1;
            res++;
        }
        
        if (pos < n) {
            return -1;
        }
        
        return res;
    }
};