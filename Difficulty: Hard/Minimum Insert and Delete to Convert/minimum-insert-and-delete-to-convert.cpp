class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        unordered_set<int> bs(begin(b), end(b));
        int n = a.size(), m = b.size();
        
        vector<int> lis;
        for (int i = 0; i < n; i++) {
            if (!bs.count(a[i])) {
                continue;
            }
            
            auto pos = lower_bound(begin(lis), end(lis), a[i]);
            
            if (pos == lis.end()) {
                lis.push_back(a[i]);
            } else {
                *pos = a[i];
            }
        }
        
        int len = lis.size();
        
        int deletions = n - lis.size();
        int insertions = m - lis.size();
        
        return deletions + insertions;
    }
};