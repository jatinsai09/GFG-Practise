class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0;
        sort(begin(arr), end(arr));
        
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] - arr[i - 1] < k) {
                res += arr[i] + arr[i - 1];
                i--;
            }
        }
        return res;
    }
};