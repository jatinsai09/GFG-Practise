class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({mat[i][0], i * m + 0});
        }
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int val = p.first, r = p.second / m, c = p.second % m;
            
            res.push_back(val);
            if (c + 1 < m) {
                pq.push({mat[r][c + 1], r * m + c + 1});
            }
        }
        
        return res;
    }
};