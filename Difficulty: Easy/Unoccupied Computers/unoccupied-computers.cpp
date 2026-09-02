class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int cur = n, miss = 0;
        vector<int> vis(26);
        
        for (const auto &c: s) {
            if (vis[c - 'A'] == 0) {
                if (cur) {
                    cur--;
                    vis[c - 'A'] = 1;
                } else {
                    vis[c - 'A'] = 2;
                    miss++;
                }
            } else if (vis[c - 'A'] == 1) {
                cur++;
            }
        }
        
        return miss;
    }
};
