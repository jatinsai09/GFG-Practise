

class Solution {
#define pii pair<int, int>
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        
        vector<int> dir = {1, 0, -1, 0, 1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first, r = it.second.first, c = it.second.second;
            
            if (d > dist[r][c]) {
                continue;
            }
            if (r == n - 1 && c == m - 1) {
                return d;
            }
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    if (dist[nr][nc] > d + grid[nr][nc]) {
                        dist[nr][nc] = d + grid[nr][nc];
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};