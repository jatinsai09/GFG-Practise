class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0, c1 = 0;
        
        for (int i = 0, j = 0; j < n; j++) {
            c1 += arr[j];
            while ((j - i + 1) - c1 > k) {
                c1 -= arr[i++];
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
