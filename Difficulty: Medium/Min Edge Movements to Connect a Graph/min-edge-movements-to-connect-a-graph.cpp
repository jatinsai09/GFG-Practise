class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int m = edges.size();
        
        vector<vector<int>> adj(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n);
        function<int(int)> dfs = [&](int u) -> int {
            vis[u] = 1;
            int c = 1;
            
            for (auto &v: adj[u]) {
                if (vis[v]) {
                    continue;
                }
                
                c += dfs(v);
            }
            return c;
        };
        
        int cc = 0, ext = 0, got = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            
            cc++;
            got += dfs(i) - 1;
        }
        
        ext = m - got;
        
        return ext >= cc - 1 ? cc - 1 : -1;
    }
};