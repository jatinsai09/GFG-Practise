class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int xr = 0;
        for (auto &i: arr) {
            xr ^= i;
        }
        
        return xr;
    }
};