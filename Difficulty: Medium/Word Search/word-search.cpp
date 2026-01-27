class Solution {
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size(),m = mat[0].size();
        int len = word.size();
        
        
        auto yes = [&](auto &&self, int i, int j, int wi) -> bool{
            if(wi == len){
                return true;
            } 
            
            if(i < 0 || j < 0 || i >= n || j >= m){
                return false;
            }
            
            if(mat[i][j] == word[wi]){
                char c = mat[i][j];
                mat[i][j]='#';
                
                bool res = self(self, i + 1, j ,wi + 1) || self(self, i, j + 1, wi + 1)
                         || self(self, i - 1, j, wi + 1) || self(self, i, j - 1, wi + 1);
                         
                mat[i][j] = c;
                
                return res;
            }
            
            return false;
        };
        
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word[0]){
                    if(yes(yes, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
