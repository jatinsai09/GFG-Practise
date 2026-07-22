class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> lis;
        for (auto& i: arr) {
            if (lis.empty() || lis.back() < i) {
                lis.push_back(i);
            } else {
                auto it = lower_bound(begin(lis), end(lis), i);
                *it = i;
            }
        }
        
        return n - lis.size();
    }
};