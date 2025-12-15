// User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int n) {
        // code here
       int ei = 0, oi = 1;
       while (ei < n && oi < n) {
           if (ei < n && arr[ei] % 2 == 0) {
               ei += 2;
           }
           
           if (oi < n && arr[oi] % 2 == 1) {
               oi += 2;
           }
           
           if (ei < n && oi < n) {
               swap(arr[ei], arr[oi]);
           }
       }
    }
};