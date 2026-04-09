class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        vector<int> res;
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (a[i] == b[j] && (res.empty() || res.back() != a[i])) {
                res.push_back(a[i]);
                i++;
                j++;
                continue;
            }
            
            if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};