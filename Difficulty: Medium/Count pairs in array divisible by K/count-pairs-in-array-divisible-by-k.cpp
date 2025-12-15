// User function Template for C++

class Solution {
  public:
    long long countKdivPairs(int a[], int n, int k) {
        // code here
        unordered_map<int, long long> f;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int rem = a[i] % k;
            if (rem == 0) {
                res += f[rem];
            } else {
                res += f[k - rem];
            }
            f[rem]++;
        }
        return res;
    }
};