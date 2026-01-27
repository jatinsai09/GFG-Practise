// User functuon template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int via = 0; via < n; via++){
            for(int u = 0; u < n; u++){
                for(int v = 0; v < n; v++){
                    if(dist[u][via] != 1e8 && dist[via][v] != 1e8){
                        dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
                    }
                }
            }
        }
    }
};