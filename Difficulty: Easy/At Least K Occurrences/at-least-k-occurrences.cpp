class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> f;
        
        for (auto &i: arr) {
            if (++f[i] == k) {
                return i;
            }
        }
        return -1;
    }
};