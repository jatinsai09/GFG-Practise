class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }

        // Step 2: indegree array
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto& neigh : adj[i]){
                indegree[neigh]++;
            }
        }

        // Step 3: queue of nodes with indegree 0
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        // Step 4: process nodes
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;
            for(auto& neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        // Step 5: if count != V → cycle exists
        return count != V;
    }
};