// User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        // Code here
        sort(start, start + n);
        sort(end, end + n);
        
        int i = 0, j = 0, cur = 0, res = 0;
        
        while (i < n) {
            if (start[i] < end[j]) {
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