class Solution {
  public:
    vector<string> validParenthesis(string &s) {
        // code here
        int n = s.size();
        int open = 0, close = 0;
        for (auto &c : s) {
            if (c != '(' && c != ')') {
                continue;
            }
            
            if (c == '(') {
                open++;
            } else {
                if (open) {
                    open--;
                } else {
                    close++;
                }
            }
        }
        set<string> st;
        
        function<void(int, int, int, int, string)> dfs =
        [&](int i, int bal, int ro, int rc, string a) {
            
            if (i == n) {
                if (bal == 0 && ro == 0 && rc == 0) {
                    st.insert(a);
                }
                return;
            }
            
            char c = s[i];
            if (c == '(') {
                if (ro > 0) {
                    dfs(i + 1, bal, ro - 1, rc, a);
                }
                dfs(i + 1, bal + 1, ro, rc, a + c);
                
            } else if (c == ')') {
                if (rc > 0) {
                    dfs(i + 1, bal, ro, rc - 1, a);
                } 
                if (bal > 0) {
                    dfs(i + 1, bal - 1, ro, rc, a + c);
                }
            } else {
                dfs(i + 1, bal, ro, rc, a + c);
            }
        };
        
        dfs(0, 0, open, close, "");
        
        vector<string> res(begin(st), end(st));
        return res;
    }
};
