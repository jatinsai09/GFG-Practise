class Solution {
  public:
    int countSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> f;
        f[0] = 1;
        int s = 0, res = 0;
        
        for (int i = 0; i < n; i++) {
            s += (arr[i] ? 1 : -1);
            res += f[s];
            f[s]++;
        }
        
        return res;
    }
};