class Solution {
  public:
    int findSubString(string& s) {
        // code here
        int n = s.size();
        set<char> st;
        for (auto &c: s) {
            st.insert(c);
        }
        int k = st.size(), res = n;
        unordered_map<char, int> f;
        
        for (int l = 0, r = 0; r < n; r++) {
            f[s[r]]++;
            while (f.size() == k) {
                res = min(res, r - l + 1);
                if (--f[s[l]] == 0) {
                    f.erase(s[l]);
                }
                l++;
            }
        }
        
        return res;
    }
};