class Solution {
  public:
    int countTriplets(vector<int> a) {
        // Code here.
        int n = a.size(), res = 0;
        
        for (int j = 1; j + 1 < n; j++) {
            int ci = 0, ck = 0;
            for (int i = 0; i < j; i++) {
                ci += (a[i] < a[j]);
            }
            for (int k = j + 1; k < n; k++) {
                ck += (a[j] < a[k]);
            }
            res += ci * ck;
        }
        
        return res;
    }
};