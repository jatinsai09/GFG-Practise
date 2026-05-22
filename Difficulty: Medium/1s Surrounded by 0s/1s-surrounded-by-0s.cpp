class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<int> dir = {1, 0, -1, 0, 1};
        vector<vector<int>> vis(n, vector<int>(m));
        
        function<void(int, int)> dfs = [&](int r, int c) -> void {
            vis[r][c] = 1;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                
                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] && !vis[nr][nc]) {
                    
                    dfs(nr, nc);
                }
            }
        };
        
        for (int i = 0; i < n; i++){
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1);
            }
        }
        
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j);
            }
            if(grid[n - 1][j] == 1 && !vis[n - 1][j]) {
                dfs(n - 1, j);
            }
        }
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    res++;
                }
            }
        }
        
        return res;
    }
};