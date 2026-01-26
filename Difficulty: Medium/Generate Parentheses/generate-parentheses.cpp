// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
    vector<string> generateParentheses(int n) {
        // code here
        vector<string> res;
        string s;
        
        function<void(int, int)> dfs = [&](int op, int cl) {
            if (op + cl == n) {
                res.push_back(s);
            }
            
            if (op < n / 2) {
                s.push_back('(');
                dfs(op+ 1, cl);
                s.pop_back();
            }
        
            if (cl < op) {
                s.push_back(')');
                dfs(op, cl + 1);
                s.pop_back();
            }
        };
        
        dfs(0, 0);
        return res;
    }
};