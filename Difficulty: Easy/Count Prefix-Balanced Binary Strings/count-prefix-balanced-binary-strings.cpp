class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
  public:
    ll modExp(ll a, ll b) {
        ll res = 1;

        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }
    int prefixStrings(int n) {
        // code here
        vector<ll> fact(2 * n + 1);
        fact[0] = 1;
        
        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        
        ll num = fact[n * 2], den = (fact[n] * fact[n]) % mod;
        
        ll res = (num * modExp(den, mod - 2)) % mod;
        res = (res * modExp(n + 1, mod - 2)) % mod;
        
        return res;
    }
};