class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), xr = 0;
        unordered_map<int,int> mp;
        mp[xr]++;
        long res = 0;
        
        for(auto& i: arr){
            xr ^= i;
            res += mp[xr ^ k];
            mp[xr]++;
        }
        
        return res;
    }
};
