class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        // code here
        vector<vector<int>> adj(n);
        for(int i=0; i<2*e; i+=2){
            int u = arr[i], v = arr[i+1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<bool> visited(n, false);
        int time = 0;
        int articulationPointFound = 0;
        
        function<int(int, int)> dfs = [&](int u, int parent) {
            visited[u] = true;
            disc[u] = low[u] = ++time;
            int children = 0;
    
            for(auto& v : adj[u]){
                if(!visited[v]){
                    children++;
                    if(dfs(v, u)) {
                        return true;
                    }
    
                    low[u] = min(low[u], low[v]);
    
                    // u is articulation point
                    if(parent != -1 && low[v] >= disc[u]){
                        articulationPointFound = 1;
                        return true;
                    }
                }
                else if(v != parent){
                    low[u] = min(low[u], disc[v]);
                }
            }
    
            // root node check
            if(parent == -1 && children > 1){
                articulationPointFound = 1;
                return true;
            }
    
            return false;
        };
        
        if (dfs(0, -1)) {
            return false;
        }
        
         for(int i=0;i<n;i++){
            if(!visited[i]) {
                return false;
            }
        }

        return true;
    }
};