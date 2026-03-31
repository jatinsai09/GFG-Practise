class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int hold = -arr[0], free = 0;
        
        for (int i = 0; i < n; i++) {
            int prev_hold = hold, prev_free = free;
            
            hold = max(prev_hold, prev_free - arr[i]);
            free = max(prev_free, prev_hold + arr[i] - k);
        }
        
        return free;
    }
};