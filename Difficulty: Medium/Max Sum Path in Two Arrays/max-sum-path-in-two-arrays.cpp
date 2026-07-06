class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n = a.size(), m = b.size(), res = 0;
        int sa = 0, sb = 0;
        
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                sa += a[i++];
            } else if (a[i] > b[j]) {
                sb += b[j++];
            } else {
                int mx = max(sa, sb);
                sa = sb = 0;
                
                res += mx + a[i];
                i++;
                j++;
            }
        }
        
        while (i < n) {
            sa += a[i++];
        } 
        while (j < m) {
            sb += b[j++];
        }
        res += max(sa, sb);
        
        return res;
    }
};