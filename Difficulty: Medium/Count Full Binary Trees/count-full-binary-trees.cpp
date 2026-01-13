class Solution {
  public:

    long long int numoffbt(long long int arr[], int n) {
        // Your code goes here
        long long res = 0;
        const int mod = 1000000007;
        sort(arr, arr + n);
        vector<long long int> dp(arr[n - 1] + 1);

        for (int i = 0; i < n; i++) {
            dp[arr[i]] = 1;
        }

        for (int i = arr[0]; i <= arr[n - 1]; i++) {
            if (dp[i]) {
                for (int j = 2 * i; j <= arr[n - 1] && (j / i <= i); j += i) {
                    if (dp[j]) {
                        dp[j] += (dp[i] * dp[j / i]);
                        if (i != j / i) {
                            dp[j] += (dp[i] * dp[j / i]);
                        }
                    }
                }
                res = (res + dp[i]) % mod;
            }
        }

       

        return res;
    }
};
