class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
            for (auto& neigh : adj[i]) {
                indegree[neigh]++;
            }

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0) {
                q.push(i);
            }

        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topoOrder.push_back(node);

            for (auto& neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return topoOrder;  // valid topological order
    }
};