// User function template for C++

class Solution {
#define ll long long int    
  public:
    long long getSubstringWithEqual012(string s) {
        // code here
        ll n = s.size(), c0 = 0, c1 = 0, c2 = 0, res = 0;
        map<pair<int, int>, ll> mp;
        mp[{0, 0}] = 1;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') c0++;
            else if(s[i] == '1') c1++;
            else c2++;
            
            pair<int, int> key = {c0 - c1, c0 - c2};
            res += mp[key]++;
        }
        
        return res;
    }
};