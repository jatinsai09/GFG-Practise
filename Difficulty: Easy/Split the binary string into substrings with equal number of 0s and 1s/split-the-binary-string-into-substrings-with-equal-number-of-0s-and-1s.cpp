class Solution {
  public:
    int maxSubStr(string s) {
        // Write your code here
        int sum = 0, res = 0;
        
        for (auto &c: s) {
            sum += (c == '1' ? 1 : -1);
            res += (sum == 0);
        }
        
        return sum == 0 ? res : -1;
    }
};
