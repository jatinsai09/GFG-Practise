class Solution {
  public:
    static bool cmp(int x, int y) {
        int bx = __builtin_popcount(x);
        int by = __builtin_popcount(y);
        
        return bx > by;
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(begin(arr), end(arr), cmp);
        return arr;
    }
};