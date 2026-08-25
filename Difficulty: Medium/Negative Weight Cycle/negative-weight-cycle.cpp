class Solution {
  public:
    bool isNegativeWeightCycle(int n, vector<vector<int>>& edges) {
        // code here
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (auto &e: edges) {
                int u = e[0], v = e[1], wt = e[2];
                
                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for (auto &e: edges) {
            int u = e[0], v = e[1], wt = e[2];
            
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                return true;
            }
        }
        
        return false;
    }
};