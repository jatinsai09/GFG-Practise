class Solution {
  public:
    vector<int> find(vector<int>& a, int x) {
        // code here
        int n = a.size(), first = -1, last = -1;
        
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (a[mid] == x) {
                first = mid;
            }
            
            if (a[mid] >= x) {
                r = mid - 1;
            }  else {
                l = mid + 1;
            }
        }
        
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (a[mid] == x) {
                last = mid;
            }
             
            if (a[mid] <= x) {
                l = mid + 1;
            }  else {
                r = mid - 1;
            }
        }
        
        return {first, last};
    }
};