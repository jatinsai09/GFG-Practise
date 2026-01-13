// User function Template for C++

class Solution {

  public:
    long long ValidPair(int a[], int n) {
        // Your code goes here
        sort(a, a + n);
        
        long long cnt = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            if (a[i] + a[j] > 0) {
                cnt += (j - i);
                j--;
            } else {
                i++;
            }
        }
        
        return cnt;
    }
};