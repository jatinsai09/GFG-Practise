class Solution {
  public:
    int intersectSize(vector<int> &a, vector<int> &b) {
        // code  here
        int res = 0;
        unordered_set<int> sa;
        for (auto &i: a) {
            sa.insert(i);
        }
        
        for (auto &i: b) {
            if (sa.find(i) != sa.end()) {
                res++;
            }
        }
        
        return res;
    }
};