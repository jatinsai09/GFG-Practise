class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].insert(i);
        }
        
        vector<int> res;
        for (auto &q: queries) {
            int l = q[0], r = q[1], k = q[2];
            
            auto lo = mp[k].lower_bound(l);
            auto hi = mp[k].upper_bound(r);
            
            
            res.push_back(distance(lo, hi));
        }
        return res;
    }
};