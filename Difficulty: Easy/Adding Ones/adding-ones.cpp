class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        vector<int> res(n);
        for (auto &i: updates) {
            res[i - 1]++;
        }
        
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }
        return res;
    }
};