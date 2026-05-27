// User function Template for C++
class Solution {
  public:
    int rev(int n){
      int rev = 0;
      while(n) {
        rev = rev * 10 + (n % 10);
        n /= 10;
      }
      return rev;
    }
    bool isPal(int n){
      return n == rev(n);    
    }
    int isSumPalindrome(int n) {
        // code here
        int i = 0;
        while(i <= 5) {
          if (isPal(n)) {
            return n;
          }
          n += rev(n);
          i++;
        }
      
        return -1;    
    }
};