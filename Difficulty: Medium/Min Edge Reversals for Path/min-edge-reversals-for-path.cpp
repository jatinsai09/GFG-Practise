// User function Template for C++

class Solution {
#define pii pair<int, int>
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pii>> adj(n + 1);
        for (const auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        
        vector<int> d(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<>> pq;
        
        pq.push({0, src});
        d[src] = 0;
        while (!pq.empty()) {
            auto [c, u] = pq.top();
            pq.pop();
            
            if (c > d[u]) {
                continue;
            }
            
            for (const auto &[v, t] : adj[u]) {
                if (d[u] + t < d[v]) {
                    d[v] = d[u] + t;
                    pq.push({d[v], v});
                }
            }
        }
        
        return (d[dst] == INT_MAX ? -1 : d[dst]);
    }
};