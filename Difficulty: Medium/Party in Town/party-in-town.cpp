class Solution {
public:
    pair<int, int> bfs(int src, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        int node = src;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > dist[node])
                node = u;

            for (auto &v : adj[u]) {
                if (dist[v - 1] == -1) {
                    dist[v - 1] = dist[u] + 1;
                    q.push(v - 1);
                }
            }
        }

        return {node, dist[node]};
    }

    int partyHouse(vector<vector<int>>& adj) {
        int n = adj.size();

        auto p1 = bfs(0, adj);
        auto p2 = bfs(p1.first, adj);

        int diameter = p2.second;

        return (diameter + 1) / 2;
    }
};