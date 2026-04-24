class Solution {
  public:
    vector<int> shortestPath(int n, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> dist(n, -1);
        dist[src] = 0;
        
        vector<vector<int>> adj(n);
        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto &v: adj[u]) {
                if (dist[v] == -1 || dist[u] + 1 < dist[v]) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
        
        return dist;
    }
};
