class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int sum = 0, res = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};