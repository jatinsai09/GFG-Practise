class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(begin(arr), end(arr));
        int n = arr.size(), res = 0;
        
        for (int l = 0, r = 0; r < n; r++) {
            while (arr[r] - arr[l] >= k) {
                l++;
            }
            
            res += (r - l);
        }
        return res;
    }
};