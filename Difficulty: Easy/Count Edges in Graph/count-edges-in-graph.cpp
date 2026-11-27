class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        // code here
        int n = adj.size(), got = 0;
        for (int i = 0; i < n; i++) {
            for (auto &j: adj[i]) {
                got += (j > i);
            }
        }
        return got;
    }
};