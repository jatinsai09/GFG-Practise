class Solution {
  public:
    int binarySubstring(string& s) {
        // code here
        int res = 0, c1 = 0;
        for (auto &c: s) {
            if (c == '1') {
                res += c1;
                c1++;
            }
        }
        return res;
    }
};