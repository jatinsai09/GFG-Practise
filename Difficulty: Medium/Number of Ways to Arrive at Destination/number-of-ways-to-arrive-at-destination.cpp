class Solution {
#define ll long long int
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) 
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<ll> dist(n, LLONG_MAX), ways(n, 0);
        
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            ll d = it.first;
            int u = it.second;
            
            if (d > dist[u]) continue;
            
            for (auto& it : adj[u]) 
            {
                int v = it.first;
                ll wt = it.second;
                
                if (dist[u] + wt < dist[v]) 
                {
                    dist[v] = dist[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (dist[u] + wt == dist[v]) 
                {
                    ways[v] += ways[u];
                }
            }
        }
        
        return ways[n - 1];
    }
};