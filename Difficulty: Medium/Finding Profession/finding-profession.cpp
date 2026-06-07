class Solution {
#define ll long long
  public:
    string profession(int level, int pos) {
        // code here
        int res = 0;
        
        while (pos > 1) {
            if (pos % 2 == 0) {
                res ^= 1;
            }
            pos = (pos + 1) / 2;
        }
        
        return res ? "Doctor" : "Engineer";
    }
};