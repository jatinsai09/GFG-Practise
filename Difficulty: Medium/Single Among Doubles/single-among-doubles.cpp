// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        // code
        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= arr[i];
        }
        
        return xr;
    }
};