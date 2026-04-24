class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size(), res = 0, prev = -1;
        
        for (auto &i : arr) {
            if (i >= prev) {
                res++;
                prev = i;
            }
        }
        
        return res;
    }
};