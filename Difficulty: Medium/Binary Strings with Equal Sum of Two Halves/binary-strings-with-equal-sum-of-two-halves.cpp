class Solution {
  public:
#define ll long long int
ll MOD = 1e9 + 7;
    ll mul(ll a, ll b, ll m) {
        return ((a % m) * (b % m)) % m;
    };
    ll modExp(ll a, ll e, ll m) {
        a %= m;
        ll r = 1;
        while (e) {
            if (e & 1) {
                r = mul(r, a, m);
            }
            a = mul(a, a, m);
            e >>= 1;
        }
    
        return r;
    }
    ll invf(ll a, ll m) {
        return modExp(a, m - 2, m);
    }
    int computeValue(int n) {
        // code here
        vector<ll> fact(2 * n + 1);

        fact[0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        ll den = (fact[n] * fact[n]) % MOD;
        
        return (fact[2 * n] * invf(den, MOD)) % MOD;
    }
};