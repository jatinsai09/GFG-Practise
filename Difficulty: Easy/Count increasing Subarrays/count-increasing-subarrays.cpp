class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size(), res = 0, c = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                c++;
                res += (c - 1);
            } else {
                c = 1;
            }
        }
        
        return res;
    }
};
