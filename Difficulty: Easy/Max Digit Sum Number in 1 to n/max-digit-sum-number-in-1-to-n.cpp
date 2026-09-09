class Solution {
#define ll long long int
public:
    ll digitSum(ll x) {
        ll sum = 0;

        while (x) {
            sum += (x % 10);
            x /= 10;
        }

        return sum;
    }
    int findMax(int n) {
        // code Here
        ll res = n, mx = digitSum(n);
        
        string s = to_string(n);
        ll m = s.size();
        
        for (int i = 0; i < m; i++) {
            if (s[i] == '0') {
                continue;
            }
            
            string t = s;
            t[i]--;
            
            for (int j = i + 1; j < m; j++) {
                t[j] = '9';
            }
            
            ll val = stoll(t);
            ll got = digitSum(val);
            
            if (got > mx || (got == mx && val > res)) {
                res = val;
                mx = got;
            }
        }
        
        return res;
    }
};
