class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
        int n = men.size();
        vector<vector<int>> rank(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rank[i][women[i][j]] = j;
            }
        }
        
        vector<int> partner(n, -1);
        vector<int> res(n, -1);
        vector<int> next(n, 0);
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        
        while (!q.empty()) {
            int m = q.front();
            q.pop();
            
            int w = men[m][next[m]];
            next[m]++;
            
            if (partner[w] == -1) {
                partner[w] = m;
                res[m] = w;
            } else {
                int m2 = partner[w];
                
                if (rank[w][m] < rank[w][m2]) {
                    partner[w] = m;
                    res[m] = w;
                    res[m2] = -1;
                    q.push(m2);
                } else {
                    q.push(m);
                }
            }
        }
        
        return res;
    }
};