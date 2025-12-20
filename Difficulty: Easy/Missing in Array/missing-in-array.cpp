class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int val = abs(arr[i]);
            if (val == n + 1) {
                continue;
            }
            arr[val - 1] *= -1;
        }
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};