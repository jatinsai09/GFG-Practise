class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(begin(arr), end(arr));
        int mn = 1;
        
        for (auto &i: arr) {
            if (i > mn) {
                return mn;
            } else {
                mn += i;
            }
        }
        
        return mn;
    }
};