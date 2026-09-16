class Solution {
  public:
    int dominantPairs(vector<int> &a) {
        // Code here
        int n = a.size();
        
        sort(begin(a), begin(a) + n / 2);
        sort(begin(a) + n / 2, end(a));
        
        int l = 0, r = n / 2, res = 0;
        while (l < n / 2) {
            while (r < n && a[l] >= a[r] * 5) {
                r++;
            }
            
            res += (r - (n / 2));
            l++;
        }
        
        return res;
    }
};