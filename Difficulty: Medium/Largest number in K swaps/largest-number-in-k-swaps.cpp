class Solution {
public:
    string ans;

    void dfs(string &s, int k, int i) {
        if (k == 0 || i == (int)s.size()) {
            if (s > ans) {
                ans = s;
            }
            return;
        }

        char mx = s[i];
        for (int j = i + 1; j < (int)s.size(); j++) {
            if (s[j] > mx) {
                mx = s[j];
            }
        }

        if (mx != s[i]) {
            k--;
        }

        for (int j = (int)s.size() - 1; j >= i; j--) {
            if (s[j] == mx) {
                swap(s[i], s[j]);
                dfs(s, k, i + 1);
                swap(s[i], s[j]);
            }
        }
    }

    string findMaximumNum(string s, int k) {
        ans = s;
        dfs(s, k, 0);
        return ans;
    }
};
