class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        int ind = 0;
        
        for (int i = 2; i <= n; i++) {
            ind = (ind + k) % i;
        }
        
        return ind + 1;
    }
};