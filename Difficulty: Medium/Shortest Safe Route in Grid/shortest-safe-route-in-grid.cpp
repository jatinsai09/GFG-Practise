class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        vector<int> dir = {1, 0, -1, 0, 1};
        vector<vector<int>> g = mat;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dir[k], nj = j + dir[k + 1];
                        
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                            continue;
                        }
                        
                        if (g[ni][nj] == 1) {
                            g[ni][nj] = 2;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (g[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
        }
        
        
        int t = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();
                
                if (j == m - 1) {
                    return t + 1;
                }
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k], nj = j + dir[k + 1];
                    
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj]) {
                        continue;
                    }
                    
                    if (g[ni][nj] == 1) {
                        q.push({ni, nj});
                        vis[ni][nj] = 1;
                    }
                }
            }
            t++;
        }
        
        return -1;
    }
};