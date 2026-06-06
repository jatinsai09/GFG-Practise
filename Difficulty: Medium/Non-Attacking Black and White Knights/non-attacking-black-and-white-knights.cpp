class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        long long t = (n * m) * (n * m - 1), a = 0;
        
        a += (n - 1) * (m - 2) * 2;
        a += (n - 2) * (m - 1) * 2;
        
        return t - a * 2;
    }
};