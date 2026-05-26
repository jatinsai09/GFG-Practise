class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        unordered_map<int, int> ind;
        ind[0] = -1;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            int ps = sum - target;
            if (ind.count(ps)) {
                return {ind[ps] + 2, i + 1};
            }
            if (!ind.count(sum)) {
                ind[sum] = i;
            }
        }
        
        return {-1};
    }
};