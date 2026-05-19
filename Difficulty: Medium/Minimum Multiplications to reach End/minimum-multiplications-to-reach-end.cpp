// User function Template for C++

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) {
            return 0;
        } 
        
        
        int steps = 0, mod = 1000;
        int vis[1001];
        memset(vis, 0, sizeof vis);
        
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int sz = q.size();

            while (sz--){
                int node = q.front();
                q.pop();
                
                if(node == end) {
                    return steps;
                } 
                
                for(auto& it : arr){
                    int newNode = (node * it) % mod;
                    if(!vis[newNode]){
                        q.push(newNode);
                        vis[newNode] = 1;
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
