class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size(), t = 0;
        
        for (auto &i : arr) {
            t += i;
        }
        
        int l = 0;
        for (auto &i : arr) {
            l += i;
            if (l == t - l) {
                return true;
            }
        }
        
        return false;
    }
};
