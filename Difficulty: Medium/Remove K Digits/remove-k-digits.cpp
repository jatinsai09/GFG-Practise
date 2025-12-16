class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n = s.size();
        string res;
        
        for (int i = 0; i < n; i++) {
            while (k > 0 && !res.empty() && res.back() > s[i]) {
                res.pop_back();
                k--;
            }
            res.push_back(s[i]);
        }
        
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }
        
        res = res.substr(i);
        if (res.empty()) {
            return "0";
        }
        return res;
    }
};