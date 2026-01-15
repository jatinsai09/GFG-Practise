class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                res[i] = res[i - 1] + 1;
            }
        }
        
        int sum = res[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                res[i] = max(res[i], res[i + 1] + 1);
            }
            sum += res[i];
        }
        
        return sum;
    }
};
