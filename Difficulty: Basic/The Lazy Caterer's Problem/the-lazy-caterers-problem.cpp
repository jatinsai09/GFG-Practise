class Solution {
  public:
    int maximum_Cuts(int n) {
        // Code here
        return n * (n + 1) / 2 + 1;
    }
};