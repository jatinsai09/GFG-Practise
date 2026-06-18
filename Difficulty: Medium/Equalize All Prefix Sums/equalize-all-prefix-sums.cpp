class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> res(n);
        res[1] = arr[1] - arr[0];
        
        int s = arr[1] + arr[0], sm = arr[0];
        for (int i = 2; i < n; i++) {
            s += arr[i];
            if (i & 1) {
                sm += arr[i / 2];
            }
            
            int mid = (i + 1) / 2;
            res[i] = (arr[mid] * mid - sm) +
                    ((s - sm - arr[mid]) - arr[mid] * (i - mid));
        }
        
        return res;
    }
};