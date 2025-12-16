// User function Template for C++

class Solution {
  public:
    string maxSum(string w, char x[], int b[], int n) {
        // code here
        int m = w.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[x[i]] = b[i];
        }
        
        int cur = 0, mx = INT_MIN, start = 0, l = 0, r = 0;
        
        for (int i = 0; i < m; i++) {
            int val;
            if (mp.find(w[i]) != mp.end()) {
                val = mp[w[i]];
            } else {
                val = (int)w[i];
            }
            
            if (val + cur < val) {
                cur = val;
                start = i;
            } else {
                cur += val;
            }
            
            if (cur > mx) {
                mx = cur;
                l = start;
                r = i;
            }
        }
        
        return w.substr(l, r - l + 1);
    }
};