class Solution {
  public:
    int findMotherVertex(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(n);
        
        for (auto &edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(n);
        int res = -1;
        
        function<void(int)> dfs = [&](int u) -> void {
            vis[u] = 1;
            for (auto &v : adj[u]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
        };
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                res = i;
            }
        }
        
        fill(begin(vis), end(vis), 0);
        
        dfs(res);
        for (int i = 0 ; i < n; i++) {
            if (!vis[i]) {
                return -1;
            }
        }
        
        return res;
    }
};