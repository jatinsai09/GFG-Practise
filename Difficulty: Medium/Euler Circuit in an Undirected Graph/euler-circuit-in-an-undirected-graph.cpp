class Solution {
  public:
     void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        for (auto& nxt : adj[node]) {
            if (!vis[nxt]) {
                dfs(nxt, adj, vis);
            }
        }
    }

    bool isEularCircuitExist(int v, vector<int> adj[]) {
        // Code here
        vector<int> degree(v, 0);

        // Count degree of each vertex
        for (int i = 0; i < v; i++) {
            degree[i] = adj[i].size();
        }

        // Check all degrees are even
        for (int i = 0; i < v; i++) {
            if (degree[i] % 2 != 0) {
                return 0;
            }
        }

        // Find first vertex with non-zero degree
        int start = -1;
        for (int i = 0; i < v; i++) {
            if (degree[i] > 0) {
                start = i;
                break;
            }
        }

        // If no edges exist, it's trivially Eulerian
        if (start == -1) {
            return 1;
        }

        // Check connectivity
        vector<bool> vis(v, false);
        dfs(start, adj, vis);

        for (int i = 0; i < v; i++) {
            if (degree[i] > 0 && !vis[i]) {
                return 0;
            }
        }

        return 1;
    }
};