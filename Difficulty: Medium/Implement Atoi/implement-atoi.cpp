class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int ind = 0, res = 0, sign = 1;
        
        while (s[ind] == ' ') {
            ind++;
        }
        
        if(s[ind] == '-' || s[ind] == '+') {
            if (s[ind++] == '-') {
                sign = -1;
            }
        }
        
        while(s[ind] >= '0' && s[ind] <= '9'){
            if (res > INT_MAX / 10){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            res = 10 * res + (s[ind++] - '0');
        }
        // Your code here
        return sign * res;
    }
};
