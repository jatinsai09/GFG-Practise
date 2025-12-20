class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n), res;
        stack<int> st;
        st.push(0);
        
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            
            if (vis[u]) {
                continue;
            }
            
            vis[u] = 1;
            res.push_back(u);
            for (int i = adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (!vis[v]) {
                    st.push(v);
                }
            }
        }
        
        return res;
    }
};