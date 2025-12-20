class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> vis(n), res;
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (vis[u]) {
                continue;
            }
            
            vis[u] = 1;
            res.push_back(u);
            for (auto& v: adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                }
            }
        }
        
        return res;
    }
};