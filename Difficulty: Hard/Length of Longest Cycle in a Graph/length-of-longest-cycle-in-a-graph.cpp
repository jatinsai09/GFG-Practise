class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> to(V, -1);
        for (int i = 0; i < edges.size(); i++) {
            to[edges[i][0]] = edges[i][1];
        }

        vector<int> vis(V, 0), inst(V, 0), dep(V, 0);
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            int u = i, d = 0;
            while (u != -1) {
                if (!vis[u]) {
                    vis[u] = 1;
                    inst[u] = 1;
                    dep[u] = d++;
                    u = to[u];
                } else {
                    if (inst[u]) {
                        ans = max(ans, d - dep[u]);
                    }
                    break;
                }
            }

            u = i;
            while (u != -1 && inst[u]) {
                inst[u] = 0;
                u = to[u];
            }
        }

        return ans;
    }
};
