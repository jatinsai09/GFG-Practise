// User function Template for C++

class Solution {
  public:
    int removals(vector<int>& arr, int k) {
        // Code here
        int n = arr.size(), res = 0;
        sort(begin(arr), end(arr));
        
        for (int i = 0, j = 0; j < n; j++) {
            while (arr[j] - arr[i] > k) {
                i++;
            }
            res = max(res, j - i + 1);
        }
        return n - res;
    }
};
