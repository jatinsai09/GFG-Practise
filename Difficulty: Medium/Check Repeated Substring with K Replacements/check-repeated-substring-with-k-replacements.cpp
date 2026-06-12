class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.size();
        if (n % k) {
            return false;
        }
        
        unordered_map<string, int> mp;
        int last = -1;
        for (int i = 0; i < n; i += k) {
            string ss = s.substr(i, k);
            last = ++mp[ss];
        }
        
        if (mp.size() == 1) {
            return true;
        }
        if (mp.size() > 2) {
            return false;
        }
        
        return last == 1 || last == (n / k) - 1;
    }
};