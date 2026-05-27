class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        
        for(auto it: arr){
            mp[it]++;
        }
        
       vector<vector<int>> res;
       for(auto& it: mp){
           res.push_back({it.first, it.second});
       }
       
       return res;
    }
};