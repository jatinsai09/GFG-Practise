class Solution {

  public:
    // Returns pendulam arrangement of arr[]
    vector<int> pendulumArrangement(vector<int>& arr) {
        // write code here
        sort(begin(arr), end(arr));
        int n = arr.size();
        int mid = (n - 1) / 2;
        
        vector<int> res(n);
        int l = mid, r = mid + 1;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                res[r++] = arr[i];
            } else {
                res[l--] = arr[i];
            }
        }
        return res;
    }
};
