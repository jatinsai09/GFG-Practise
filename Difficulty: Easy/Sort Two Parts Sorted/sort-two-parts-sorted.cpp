class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        int n = arr.size(), m = (n + 1) / 2;
        
        while (m) {
            int i = 0, j = m;
            while (j < n) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
                i++;
                j++;
            }
            if (m == 1) {
                break;
            }
            m = (m + 1) / 2;
        }
    }
};