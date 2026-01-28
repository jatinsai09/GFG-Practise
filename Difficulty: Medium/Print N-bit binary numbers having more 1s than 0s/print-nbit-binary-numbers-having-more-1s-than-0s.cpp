// User function template for C++
class Solution {
  public:
    void dfs(int n, int ones, int zeros, string cur, vector<string>& ans) {
        if ((int)cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        
        dfs(n, ones + 1, zeros, cur + '1', ans);
        
        if (ones > zeros) {
            dfs(n, ones, zeros + 1, cur + '0', ans);
        }
    }
    vector<string> NBitBinary(int n) {
        // Your code goes here
        vector<string> ans;
        dfs(n, 0, 0, "", ans);
        return ans;
    }
};