class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        int t = n * n;
        vector<int> jump(t + 1, -1);
        
        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }
        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }
        
        queue<int> q;
        vector<int> vis(t + 1);
        int moves = 0;
        
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                
                if (cur == t) {
                    return moves;
                }
                
                for (int d = 1; d <= 6; d++) {
                    int nxt = cur + d;
                    if (nxt > t) {
                        continue;
                    }
                    
                    if (jump[nxt] != -1) {
                        nxt = jump[nxt];
                    }
                    
                    if (!vis[nxt]) {
                        q.push(nxt);
                        vis[nxt] = 1;
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};