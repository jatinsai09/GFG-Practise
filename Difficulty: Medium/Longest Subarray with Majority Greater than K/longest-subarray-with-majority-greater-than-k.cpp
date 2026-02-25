class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int pref = 0, res = 0;
        for(int i = 0; i < n; i++) {
            pref += (arr[i] > k ? 1 : -1);
            
            if(pref > 0) {
                res = i + 1;
            }
            else {
                if(mp.find(pref - 1) != mp.end()) {
                    res = max(res, i - mp[pref - 1]);
                }
            }
            
            if(mp.find(pref) == mp.end()) {
                mp[pref] = i;
            }
        }
        
        return res;
    }
};