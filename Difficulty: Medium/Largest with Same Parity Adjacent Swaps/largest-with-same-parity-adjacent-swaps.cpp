class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &a) {
        // code here
        int n = a.size();
        vector<int> res;
        
        for (int i = 0; i < n;) {
            int j = i;
            vector<int> v;
            
            while (j < n && a[i] % 2 == a[j] % 2) {
                v.push_back(a[j++]);
            }
            sort(rbegin(v), rend(v));
            
            for (auto &it: v) {
                res.push_back(it);
            }
            
            i = j;
        }
        
        return res;
    }
};