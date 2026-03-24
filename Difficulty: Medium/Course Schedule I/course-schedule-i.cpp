class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<int> indeg(n);
        vector<vector<int>> adj(n);
        
        for (auto &pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indeg[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int c = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            c++;
            
            for (auto &v: adj[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return c == n;
    }
};