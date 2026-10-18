class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int res = 0;
        
        while (n > 1) {
            if (n % 3) {
                n--;
            } else {
                n /= 3;
            }
            res++;
        }
        return res;
    }
};