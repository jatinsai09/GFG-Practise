class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        int n = s.size();
        
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        
        string res = "";
        for (const auto &w: d) {
            int prev = -1;
            bool yes = true;
            
            for (const auto &c: w) {
                auto &p = pos[c - 'a'];
                
                auto it = upper_bound(begin(p), end(p), prev);
                
                if (it == end(p)) {
                    yes = false;
                    break;
                }
                
                prev = *it;
            }
            
            if (yes) {
                if (w.size() > res.size()) {
                    res = w;
                } else if (w.size() == res.size() && w < res) {
                    res = w;
                }
            }
        }
        
        return res;
    }
};