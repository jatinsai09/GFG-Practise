class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> prev;
        prev[0] = -1;
        int p = 0, res = 0;
        
        for (int i = 0; i < n; i++) {
            p += arr[i];
            
            if (prev.count(p)) {
                res = max(res, i - prev[p]);
            } else {
                prev[p] = i;
            }
        }
        
        return res;
    }
};