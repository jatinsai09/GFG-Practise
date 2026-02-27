// User function Template for C++

class Solution {
  public:
    int n, m, res = -1;
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void dfs(int x, int y, int xd, int yd, 
             vector<vector<int>> &mat, 
             vector<vector<int>> &vis, 
             int len) {
        
        if(x == xd && y == yd) {
            res = max(res, len);
            return;
        }
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(mat[nx][ny] == 1 && vis[nx][ny] == 0) {
                    dfs(nx, ny, xd, yd, mat, vis, len + 1);
                }
            }
        }
        
        vis[x][y] = 0;
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
        // code here
        n = matrix.size();
        m = matrix[0].size();
        
        if(matrix[xs][ys] == 0 || matrix[xd][yd] == 0) {
            return -1;
        }
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        dfs(xs, ys, xd, yd, matrix, vis, 0);
        
        return res;
    }
};