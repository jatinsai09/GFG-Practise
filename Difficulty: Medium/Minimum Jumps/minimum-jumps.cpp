class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (!arr[0]) {
            return -1;
        }
        
        int mx = 0, cur = 0, jumps = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, i + arr[i]);
            
            if (mx >= n - 1) {
                return jumps + 1;
            }
            
            if (i == cur) {
                if (mx == i) {
                    return -1;
                }
                
                
                jumps++;
                cur = mx;
            }
        }
        return -1;
    }
};
