class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int n = s.size(), r1 = 0;
        for (int i = 0; i < n; i++) {
            r1 += ((s[i] - '0') != i % 2);
        }
        
        return min(r1, n - r1);
    }
};