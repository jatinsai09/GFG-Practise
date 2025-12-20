class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long cur = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                cur += arr[i];
                ans = max(ans, cur);
            } else {
                cur = 0;
            }
        }

        return ans;
    }
};