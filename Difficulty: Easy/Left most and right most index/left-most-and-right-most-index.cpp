class Solution {
    #define ll long long 
  public:
    pair<long, long> indexes(vector<long long> arr, long long x) {
        // code here
        ll n = arr.size(), first = -1, last = -1;
        
        ll l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (arr[m] == x) {
                first = m;
                r = m - 1;
            } else if (arr[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (arr[m] == x) {
                last = m;
                l = m + 1;
            } else if (arr[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return {first, last};
    }
};