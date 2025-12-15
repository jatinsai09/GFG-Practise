class Solution {
    #define ll long long
  public:
    long long countTriplets(int n, long long sum, long long a[]) {
        // Your code goes here
        sort(a, a + n);
        ll res = 0;
        for (int i = 0; i + 2 < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                ll s = a[i] + a[j] + a[k];
                if (s < sum) {
                    res += (k - j);
                    j++;
                }  else {
                    k--;
                }
            }
        }
        
        return res;
    }
};