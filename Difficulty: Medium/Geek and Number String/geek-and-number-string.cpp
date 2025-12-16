// User function template for C++

class Solution {
  public:
    int minLength(string s, int n) {
        // code here
        unordered_map<char, char> mp;
        for (char c = '1'; c < '9'; c += 2) {
            mp[c] = char(c + 1);
            mp[char(c + 1)] = c;
        }
        mp['0'] = '9';
        mp['9'] = '0';
        string res;
        for (int i = 0; i < n; i++) {
            if (!res.empty() && mp[s[i]] == res.back()) {
                res.pop_back();
            } else {
                res.push_back(s[i]);
            }
        }
        
        return res.size();
    }
};
