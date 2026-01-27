class Solution {
  public:
    int dfs(int node, int dest, vector<int> adj[]) {
        if (node == dest) {
            return 1;
        }

        int paths = 0;
        for (auto& next : adj[node]) {
            paths += dfs(next, dest, adj);
        }
        return paths;
    }
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        return dfs(source, destination, adj);
    }
};