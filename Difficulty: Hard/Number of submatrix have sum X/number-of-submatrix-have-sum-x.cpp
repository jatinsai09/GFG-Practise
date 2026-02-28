class Solution {
  public:
    int isPresent(vector<vector<int>> &mat, int i, int j, int target)
    {
        int res = 0, i0 = i - 1, j0 = j - 1;
        while (i0 >= 0 and j0 >= 0){
            int sum = mat[i][j] - (mat[i0][j] + mat[i][j0]) + mat[i0--][j0--];
            res += (sum == target);
        }
        
        if (i0 == -1 and j0 != -1){
            int sum = mat[i][j] - mat[i][j0];
            res += (sum == target);
        }
        if (i0 != -1 and j0 == -1){
            int sum = mat[i][j] - mat[i0][j];
            res += (sum == target);
        }
        return res;
    }
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        {
            for(int i = 0; i < n; i++){
                for(int j = 1; j < m; j++){
                        mat[i][j] += mat[i][j - 1];
                }
            }
            for(int i = 1;i < n; i++){
                for(int j = 0; j < m; j++){
                        mat[i][j] += mat[i - 1][j];
                }
            }
        }
        
        
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == x and i == j) {
                    res++;
                }
                res += isPresent(mat, i, j, x);
            }
        }
        
        return res;
    }
};