class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int res = arr[0], sum = arr[0];
        for (int i = 1; i < n; i++) {
            sum = max(sum + arr[i], arr[i]);
            res = max(res, sum);
        }
        
        return res;
    }
};