class Solution {
#define ll long long int
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        int n = arr.size();
        sort(begin(arr), end(arr));
        int l = 0, r = n - 1;
        
        while (l < r) {
            long long p = 1LL * arr[l] * arr[r];
            
            if (p == target) {
                return true;
            } else if (p < target) {
                l++;
            } else {
                r--;
            }
        }
        return false;
    }
};