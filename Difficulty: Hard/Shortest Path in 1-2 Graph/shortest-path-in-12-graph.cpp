class Solution {
#define pii pair<int, int>
  public:
    int shortestPath(int n, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pii>> adj(n);
        for (const auto& e: edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(n, INT_MAX);
        queue<pii> q;
        
        q.push({src, 0});
        dist[src] = 0;
        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();
            
            for (const auto& [v, wt]: adj[u]) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    q.push({v, dist[v]});
                }
            }
        }
        
        return (dist[dest] == INT_MAX ? -1 : dist[dest]);
    }
};