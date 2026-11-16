class Solution {
  public:
    int findKthSmall(vector<int>& a, int k) {
        // code here
        int n = a.size();
        sort(begin(a), end(a));
        
        int l = 0, r = n - 1, m;
        while (l <= r) {
            m = (l + r) / 2;
            
            int miss = a[m] - (m + 1);
            
            if (miss < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } 
        
        int miss = a[r] - (r + 1);
        
        return a[r] + (k - miss);
    }
};