class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<int> &vis, int &cntV, int &cntDeg) {
        vis[u] = 1;
        cntV++;
        cntDeg += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, cntV, cntDeg);
            }
        }
    }

    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> adj[v + 1];
        for (auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(v + 1, 0);
        int ans = 0;

        for (int i = 1; i <= v; i++) {
            if (!vis[i]) {
                int cntV = 0, cntDeg = 0;
                dfs(i, adj, vis, cntV, cntDeg);

                int cntE = cntDeg / 2;
                if (cntE == (cntV * (cntV - 1)) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
