class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
         vector<vector<int>> adj(V);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(V), low(V), vis(V, 0), mark(V, 0);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            vis[u] = 1;
            tin[u] = low[u] = timer++;
            int ch = 0;

            for (auto& v : adj[u]) {
                if (v == p) continue;

                if (!vis[v]) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);

                    if (low[v] >= tin[u] && p != -1) {
                        mark[u] = 1;
                    }
                    ch++;
                } else {
                    low[u] = min(low[u], tin[v]);
                }
            }

            if (p == -1 && ch > 1) {
                mark[u] = 1;
            }
        };

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1);
            }
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (mark[i]) {
                res.push_back(i);
            }
        }

        if (res.size() == 0) {
            return {-1};
        }

        return res;
    }
};