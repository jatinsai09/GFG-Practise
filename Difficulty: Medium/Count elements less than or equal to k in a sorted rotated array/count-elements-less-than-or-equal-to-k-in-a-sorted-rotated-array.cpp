class Solution {
public:
    int countLessEqual(vector<int> &arr, int x) {
        int n=arr.size(), l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > arr[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int p = r;
        
        int c1 = 0, c2 = 0;
        l = p; r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] <= x) {
                c1 = m - p + 1;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        l = 0; r = p - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] <= x) {
                c2 = m + 1;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return c1 + c2;
    }
};