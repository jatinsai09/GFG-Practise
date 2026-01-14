
class Solution {
  public:
    long long dyckPaths(int n) {
        // code here
        if (n <= 1)
        {
            return 1;
        }

        long long k = n, res = 1;

        for (long long i = 0; i < k; i++)
        {
            res = res * (2 * k - i) / (i + 1);
        }

        return res / (k + 1);
    }
};