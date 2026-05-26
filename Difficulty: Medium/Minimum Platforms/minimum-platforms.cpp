class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        int n = arr.size(), res = 0, cur = 0;
        
        int i = 0, j = 0;
        while (i < n) {
            if (arr[i] <= dep[j]) {
                cur++;
                i++;
            } else {
                cur--;
                j++;
            }
            res = max(res, cur);
        }
        
        return res;
    }
};
