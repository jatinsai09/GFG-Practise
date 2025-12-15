// User function template for C++
class Solution {
  public:
    #define ll long long

    ll countSubarray(int arr[], int n, int k) {
        // code here
        ll total = 1LL * n * (n + 1) / 2, c = 0, res = 0;
        
        for (ll i = 0; i < n; i++) {
            if (arr[i] <= k) {
                c++;
            } else {
                res += c * (c + 1) / 2;
                c = 0;
            }
        }
        res += c * (c + 1) / 2;
        
        return total - res;
    }
};