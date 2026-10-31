class Solution {
#define ll long long int
  public:
    int maximumSubarray(vector<int>& a) {
        // code here
        ll n = a.size();
        if (n == 1) {
            return a[0] * a[0];
        }
        
        vector<ll> suf(n);
        
        ll s = 0;
        for (int i = n - 1; i >= 0; i--) {
            s = max({0LL, 1LL * a[i], s + a[i]});
            suf[i] = s;
        }
        
        ll pre = 0, res = INT_MIN;
        for (int i = 0; i + 1 < n; i++) {
            res = max(res, pre + a[i] * a[i] + suf[i + 1]);
            pre = max({0LL, 1LL * a[i], pre + a[i]});
        }
        
        res = max(res, pre + a[n - 1] * a[n - 1]);
        
        return res;
    }
};