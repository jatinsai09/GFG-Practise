class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), cur = 0;
        for(int i = 0; i < k; i++){
            cur ^= arr[i];
        }
        
        int res = cur;
        for(int i = k; i < n; i++){
            cur ^= arr[i - k];
            cur ^= arr[i];
            if(cur > res){
                res = cur;
            }
        }
        
        return res;
    }
};