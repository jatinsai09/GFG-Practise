class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n < 3) {
            return -1;
        }
        
        int f = INT_MIN, s = INT_MIN, t = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > f) {
                t = s;
                s = f;
                f = arr[i];
            } else if (arr[i] > s) {
                t = s;
                s = arr[i];
            } else if (arr[i] > t) {
                t = arr[i];
            }
        }
        
        return t;
    }
};