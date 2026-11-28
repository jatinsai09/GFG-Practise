class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        // code here
        int n = adj.size();
        vector<int> vis(n);
        
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (cur == v) {
                return true;
            }
            
            for (auto &nxt: adj[cur]) {
                if (!vis[nxt]) {
                    q.push(nxt);
                    vis[nxt]  = 1;
                }
            }
        }
        
        return false;
    }
};