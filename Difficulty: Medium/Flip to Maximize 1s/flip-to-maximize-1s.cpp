class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size(), res = 0;
        int sum = 0, c1 = 0;
        for (auto &i: arr) {
            c1 += (i == 1);
            sum += (i == 1 ? -1 : 1);
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res + c1;
    }
};