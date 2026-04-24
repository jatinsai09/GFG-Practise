// User function Template for C++

class Solution {
  public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> res(n), degree(n);
        vector<vector<int>> adj(n);
        for (auto &e: edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            degree[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
                res[i] = 1;
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto &v: adj[u]) {
                if (--degree[v] == 0) {
                    q.push(v);
                }
                res[v] = max(res[v], res[u] + 1);
            }
        }
        return res;
    }
};