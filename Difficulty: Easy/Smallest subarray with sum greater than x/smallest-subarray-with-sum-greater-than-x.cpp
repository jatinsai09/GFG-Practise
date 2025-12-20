class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int n = arr.size(), sum = 0, res = n + 1;

        for (int l = 0, r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > x) {
                res = min(res, r - l + 1);
                sum -= arr[l++];
            }
        }

        if (res == n + 1) {
            return 0;
        }

        return res;
    }
};