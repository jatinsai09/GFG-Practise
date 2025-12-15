class Solution {

  public:
    vector<int> findMissing(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n = a.size(), m = b.size();
        vector<int> res;
        
        unordered_set<int> s;
        for (auto &i: b) {
            s.insert(i);
        }
        
        for (auto &i: a) {
            if (s.find(i) == s.end()) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
