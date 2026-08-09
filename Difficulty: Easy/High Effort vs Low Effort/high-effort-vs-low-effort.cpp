class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();
        vector<int> prev(3);
        prev[1] = l[0],
        prev[2] = h[0];
        
        for (int i = 1; i < n; i++) {
            vector<int> cur(3);
            
            cur[0] = max({prev[0], prev[1], prev[2]});
            cur[1] = l[i] + max({prev[0], prev[1], prev[2]});
            cur[2] = h[i] + prev[0];
            
            prev = cur;
        }
        
        return max({prev[0], prev[1], prev[2]});
    }
};