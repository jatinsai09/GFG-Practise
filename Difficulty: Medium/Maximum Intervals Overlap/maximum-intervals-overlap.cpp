class Solution {

  public:
    vector<int> findMaxGuests(int Entry[], int Exit[], int n) {
        // Your code goes here
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({Entry[i], 1});
            vp.push_back({Exit[i], -1});
        }
        
        sort(begin(vp), end(vp), [&](auto& a, auto& b){
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        
        int cur = 0, mx = 0, res = 0;
        
        for (int i = 0; i < 2 * n; i++) {
            cur += vp[i].second;
            
            if (cur > mx) {
                mx = cur;
                res = vp[i].first;
            }
        }
        
        return {mx, res};
    }
};