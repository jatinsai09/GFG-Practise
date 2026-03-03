class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        
        int l = 0, res = 0;
        
        for(int r = 0; r < n; r++){
            mp[arr[r]]++;
            
            while(mp.size() > 2){
                if(--mp[arr[l]] == 0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};