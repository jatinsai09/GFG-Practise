class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
  public:
    int minOperations(vector<int> &b) {
        // code here
        int n = b.size();
        vector<bool> vis(n);
        vector<ll> v;
        
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            
            ll cyc = 0, j = i;
            
            while(!vis[j]) {
                cyc++;
                vis[j] = true;
                j = b[j] - 1;
            } 
            
            v.push_back(cyc);
        }
        
        while (v.size() > 1) {
            ll x = v.back(); v.pop_back();
            ll y = v.back(); v.pop_back();
            
            ll z = (x * y) / (__gcd(x, y));
            z %= mod;
            
            v.push_back(z);
        }
        
        return v[0];
    }
};