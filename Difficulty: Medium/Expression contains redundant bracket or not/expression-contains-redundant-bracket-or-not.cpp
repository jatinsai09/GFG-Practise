class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        for (auto& c : s) {
            if (c != ')') {
                st.push(c);
            } else {
                bool ok = false;
                while (st.top() != '(') {
                    char t = st.top();
                    st.pop();
                    if (t == '+' || t == '-' || t == '*' || t == '/') {
                        ok = true;
                    }
                }
                st.pop();
                if (!ok) {
                    return true;
                }
            }
        }
        return false;
    }
};
