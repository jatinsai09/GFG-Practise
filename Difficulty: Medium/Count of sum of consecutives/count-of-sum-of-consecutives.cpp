class Solution {
  public:
    int getCount(int n) {
        // code here
        int cnt = 0;
        
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i % 2 == 1) {
                    cnt++;
                }
                int d = n / i;
                if(d != i && d % 2 == 1) {
                    cnt++;
                }
            }
        }
        
        return cnt - 1;
    }
};