// User function Template for C++

class Solution {
  public:
    int makeProductOne(int a[], int n) {
        // code here
        int res = 0, neg = 0, zero = 0;
        
        for (int  i = 0; i < n; i++) {
            if (a[i] < -1) {
                res += (-1 - a[i]);
                neg++;
            } else if (a[i] > 1) {
                res += (a[i] - 1);
            } else if (a[i] == 0) {
                res++;
                zero++;
            } else if (a[i] == -1) {
                neg++;
            }
        } 
        
        if (neg % 2 == 0) {
            return res;
        }
        
        return res + (zero == 0) * 2;
    }
};