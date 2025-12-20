// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr, int n) {
        // code here
        long long s1 = 0, s2 = 0, g;
        for (int i = 0; i < n; i++) {
            g = max(s2 + arr[i], s1);
            s2 = s1;
            s1 = g;
        }
        
        return s1;
    }
};