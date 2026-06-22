class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n = height.size(), ht;
        int l = 0, r = n - 1, res = 0;
        
        while (l <= r) {
            if (height[l] <= height[r]) {
                ht = height[l++];
            } else {
                ht = height[r--];
            }
            res = max(res, ht * (r - l));
        }
        
        return res;
    }
};