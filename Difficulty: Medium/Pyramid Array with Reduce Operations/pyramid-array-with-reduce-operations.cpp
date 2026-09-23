class Solution {
#define ll long long
  public:
    int formPyramid(vector<int>& a) {
        // code here
        int n = a.size();
        vector<ll> l(n), r(n);
        
        l[0] = 1;
        for (int i = 1; i < n; i++) {
            l[i] = min(1LL * a[i], l[i - 1] + 1);
        }
        
        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = min(1LL * a[i], r[i + 1] + 1);
        }

        ll total = 0;
        for (const auto &i: a) {
            total += i;
        }

        ll best = 0;
        for (int i = 0; i < n; i++) {
            ll h = min(l[i], r[i]);
            
            best = max(best, h * h);
        }

        return total - best;
    }
};