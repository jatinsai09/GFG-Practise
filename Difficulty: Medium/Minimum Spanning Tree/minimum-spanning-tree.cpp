class Solution {
#define pii pair<int, int>
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pii>> adj(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> vis(n);
        
        int res = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();
            
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            res += wt;
            
            for (auto &[v, w] : adj[u]) {
                if (!vis[v]) {
                    pq.push({w, v});
                }
            }
        }
        return res;
    }
};