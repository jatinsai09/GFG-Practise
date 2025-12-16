// User function Template for C++

class Solution {
  public:
    int min_sprinklers(int gallery[], int n) {
        // code here
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; i++) {
            if (gallery[i] != -1) {
                int l = i - gallery[i], r = i + gallery[i];
                v.push_back({l, r});
            }
        }
        
        sort(begin(v), end(v));
        
        int i = 0, cover = 0, res = 0;
        
        while (cover < n) {
            int mx = -1;
            
            while (i < n && v[i].first <= cover) {
                mx = max(mx, v[i].second);
                i++;
            }
            
            if (mx < cover) {
                return -1;
            }
            
            cover = mx + 1;
            res++;
        }
        
        return res;
    }
};
