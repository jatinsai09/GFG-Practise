class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        // code here
        if (mat[r][c] == '#') {
            return 0;
        }
        
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> mnu(n, vector<int>(m, INT_MAX)), mnd(mnu);
        
        vector<int> dir = {1, 0, -1, 0, 1};
        
        queue<vector<int>> q;
        q.push({r, c, 0, 0});
        mnu[r][c] = mnd[r][c] = 0;
       
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            
            int x = v[0], y = v[1], cu = v[2], cd = v[3];
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny =  y + dir[i + 1];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || mat[nx][ny] == '#') {
                    continue;
                }
                
                int ncu = cu + (nx < x), ncd = cd + (nx > x);
                
                if (ncu <= u && ncd <= d) {
                    if (ncu < mnu[nx][ny] || ncd < mnd[nx][ny]) {
                        mnu[nx][ny] = ncu;
                        mnd[nx][ny] = ncd;
                        q.push({nx, ny, ncu, ncd});
                    }
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += (mnu[i][j] <= u);
            }
        }
        
        return cnt;
    }
};