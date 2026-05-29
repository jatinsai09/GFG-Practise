// User function Template for C++

class Solution {
  public:
    int prime_Sum(int n) {
        // Code here
        vector<bool> isp(n + 1, true);
        isp[0] = false;
        isp[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isp[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isp[j] = false;
                }
            }
        }
        
        long long sum = 0;
        for (int i = 2; i <= n; i++) {
            if (isp[i]) {
                sum += i;
            }
        }
        
        return sum;
    }
};