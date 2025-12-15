class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        unordered_map<int, int> f;
        f[0] = 1;
        int s = 0, res = 0;
        
        for (auto &i: arr) {
            s += i;
            res += f[s]++;
        }
        
        return res;
    }
};