class Solution {
  public:
    int countDistinctSubarray(int a[], int n) {
        // code here.
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
        }
        int k = s.size(), res = 0;
        unordered_map<int, int> f;
        
        for (int l = 0, r = 0; r < n; r++) {
            f[a[r]]++;
            while (f.size() == k) {
                res += (n - r);
                if (--f[a[l]] == 0) {
                    f.erase(a[l]);
                }
                l++;
            }
        }
        
        return res;
    }
};
