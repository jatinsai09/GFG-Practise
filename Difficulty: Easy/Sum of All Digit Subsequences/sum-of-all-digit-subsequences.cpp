class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
  public:
    ll modExp(ll a, ll b) {
        ll res = 1;
        
        a %= mod;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int subsequenceSum(string &s) {
        // code here
        ll n = s.size(), res = 0;
        
        ll m = modExp(2LL, n - 1);
        
        for (auto &c: s) {
            ll d = c - '0';
            
            res += (d * m);
            res %= mod;
        }
        return res;
    }
};