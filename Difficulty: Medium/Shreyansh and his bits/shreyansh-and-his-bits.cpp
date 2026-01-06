// User function Template for C++

class Solution {
  public:
    long long nCr[50][50];

    void build() {
        nCr[0][0] = 1;
        for(int i = 0; i < 50; i++) {
            nCr[i][0] = nCr[i][i] = 1;
            for(int j = 1; j < i; j++) {
                nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            }
        }
    }
    
    long long count(long long x) {
        // Code Here
        if (nCr[0][0] == 0) build();

        int k = __builtin_popcountll(x);
        long long res = 0;
    
        for(int i = 63; i >= 0 && k > 0; i--) {
            if(x & (1LL << i)) {
                if(i >= k) {
                    res += nCr[i][k];
                }
                k--;
            }
        }
    
        return res;
    }
};