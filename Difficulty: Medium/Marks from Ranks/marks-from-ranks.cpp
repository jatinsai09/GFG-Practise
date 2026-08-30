class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size(), m = rank.size();
        
        vector<int> ind(m);
        for (int i = 0; i < m; i++) {
            ind[i] = i;
        }
        sort(begin(ind), end(ind), [&](int x, int y){
            return rank[x] < rank[y];
        });
        
        vector<int> res(m);
        
        int miss = l[0] - 1;
        for (int i = 0, j = 0; i < m; i++) {
            while (j < n && r[j] - miss < rank[ind[i]]) {
                j++;
                miss += l[j] - r[j - 1] - 1;
            }
            
            if (j == n) {
                int rnk = r[n - 1] - miss;
                
                res[ind[i]] = r[n - 1] + (rank[ind[i]] - rnk);
            } else {
                int rnk = r[j] - miss;
                
                res[ind[i]] = r[j] - (rnk - rank[ind[i]]);
            }
        }
        
        return res;
    }
};