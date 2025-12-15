class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> vis(n);
        vector<pair<int, int>> vp;
        
        for (int i = 0; i < n; i++) {
            vp.push_back({arr[i], i});
        }
        
        sort(begin(vp), end(vp));
        
        int swaps = 0, len, cur;
        
        for (int i = 0; i < n; i++) {
            if (vis[i] || vp[i].second == i) {
                continue;
            }
            
            
            len = 0;
            cur = i;
            
            while (!vis[cur]) {
                vis[cur] = 1;
                len++;
                cur = vp[cur].second;
            }
            
            swaps += len - 1;
        }
        
        return swaps;
    }
};