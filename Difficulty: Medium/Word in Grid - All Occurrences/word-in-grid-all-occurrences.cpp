class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size(), m = mat[0].size(), len = word.size();
        vector<vector<int>> res;
        
        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };
        
        auto check = [&](int i, int j, int dr, int dc) -> bool {
            for (int k = 0; k < len; k++) {
                int ni = i + dr * k, nj = j + dc * k;
                
                if (ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] != word[k]) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    for (const auto& [dr, dc]: dir) {
                        if (check(i, j, dr, dc)) {
                            res.push_back({i, j});
                            break;
                        }
                    }
                }
            }
        }
        
        sort(begin(res), end(res));
        return res;
    }
};