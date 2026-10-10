class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here 
        while (b > 0) {
            int r = b % a;
            
            if (r > 1 && r < a - 1) {
                return false;
            }
            
            if (r == a - 1 && r > 1) {
                b++;
            }
            b /= a;
        }
        return true;
    }
};