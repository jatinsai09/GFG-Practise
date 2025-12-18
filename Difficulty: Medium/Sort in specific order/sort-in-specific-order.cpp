class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(begin(arr), end(arr), [&](int a, int b){
            int r1 = a & 1, r2 = b & 1;
            if (r1 != r2) {
               return r1 > r2; // both are of different parity
            } 
            if (r1) {
                return a > b; // both are odd
            }
            return a < b; // both are even
        });
    }
};