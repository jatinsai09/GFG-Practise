// User function Template for C++

class Solution {
  public:
    int decimalEquivalent(string N, int b) {
        // code here
        int n = N.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int val;
            
            if (N[i] >= '0' && N[i] <= '9') {
                val = N[i] - '0';
            }
            else {
                val = N[i] - 'A' + 10;
            }
            
            if (val >= b) {
                return -1;
            }
            
            res = res * b + val;
        }
        
        return res;
    }
};