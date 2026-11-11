class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (++mp[arr[i]] == 1) {
                d++;
            }
            if (i >= k + 1) {
                if (--mp[arr[i - k - 1]] == 0) {
                    d--;
                }
            }
            
            if (i >= k && d <= k) {
                return true;
            }
        }
        
        return false;
    }
};