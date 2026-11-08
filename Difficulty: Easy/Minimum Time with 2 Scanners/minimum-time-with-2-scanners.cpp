class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        // code here
        int nxt1 = 0, nxt2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (nxt1 + s1 < nxt2 + s2) {
                nxt1 += s1;
            } else {
                nxt2 += s2;
            }
        }
        return max(nxt1, nxt2);
    }
};