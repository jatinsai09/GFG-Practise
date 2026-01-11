class Solution {
  public:
    bool dfs(int u, int k, vector<vector<pair<int,int>>> &adj, vector<int> &vis) {
        if (k <= 0) {
            return true;
        }

        vis[u] = 1;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (!vis[v]) {
                if (dfs(v, k - w, adj, vis)) {
                    return true;
                }
            }
        }

        vis[u] = 0;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) {
        //  Code Here
        vector<vector<pair<int,int>>> adj(V);

        for (int i = 0; i < 3 * E; i += 3) {
            int u = a[i], v = a[i + 1], w = a[i + 2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(V, 0);
        return dfs(0, k, adj, vis);
    }
};
