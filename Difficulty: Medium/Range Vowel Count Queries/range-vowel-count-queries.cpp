class Solution {
  public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        int n = s.size();
        vector<int> pf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pf[i + 1] = pf[i] + isVowel(s[i]);
        }
        
        vector<int> res;
        for (auto &q : queries) {
            res.push_back(pf[q[1] + 1] - pf[q[0]]);
        }
        return res;
    }
};