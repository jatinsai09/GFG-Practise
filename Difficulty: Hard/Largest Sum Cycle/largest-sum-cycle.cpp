class Solution {
#define ll long long
  public:
    int largestSumCycle(vector<int>& edge) {
        // code here
        ll n = edge.size(), res = -1;
        
        vector<bool> vis(n), pathVis(n);
        
        function<ll(ll)> dfs = [&](ll u) -> ll {
          if (u == -1) {
              return -1;
          }  
          
          if (pathVis[u]) {
              ll got = 0, cur = u;
              
              do {
                  got += cur;
                  cur = edge[cur];
              } while (cur != u);
              return got;
          }
          
          vis[u] = 1;
          pathVis[u] = 1;
          
          ll got = dfs(edge[u]);
          
          pathVis[u] = 0;
          
          return got;
          
        };
        
        
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            
            res = max(res, dfs(i));
        }
        
        return res;
    }
};