// User function teamplate for C++

class Solution {
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        // code here
        int i = 0, j = m - 1, d = INT_MAX;
        int a = 0, b = 0;

        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j], diff = abs(sum - x);

            if (diff < d) {
                d = diff;
                a = arr[i];
                b = brr[j];
            }

            if (sum > x) {
                j--;
            } else {
                i++;
            }
        }
        
        return {a, b};
    }
};