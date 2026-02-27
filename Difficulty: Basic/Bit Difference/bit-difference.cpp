class Solution {
  public:
    int countBitsFlip(int a, int b) {
        // code here
        int xr = a ^ b, cnt=0;
        while(xr > 0){
            cnt += xr & 1;
            xr = xr >> 1;
        }
        return cnt;
    }
};