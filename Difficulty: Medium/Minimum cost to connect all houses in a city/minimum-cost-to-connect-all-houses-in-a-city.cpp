class Solution {
  public:
    int minCost(vector<vector<int>>& a) {
        // code here
        int n = a.size();
        
        vector<int> d(n, INT_MAX), vis(n, 0);
        
        d[0] = 0;
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            int u = -1;
            
            for (int j = 0; j < n; j++) {
                if (!vis[j] && (u == -1 || d[j] < d[u])) {
                    u = j;
                }
            }
            
            vis[u] = 1;
            res += d[u];
            
            for (int v = 0; v < n; v++) {
                if (vis[v] == 0) {
                    int cost = abs(a[u][0] - a[v][0]) + abs(a[u][1] - a[v][1]);
                    d[v] = min(d[v], cost);
                }
            }
        }
        
        return res;
    }
};