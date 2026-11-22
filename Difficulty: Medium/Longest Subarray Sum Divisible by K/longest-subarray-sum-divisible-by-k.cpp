// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& a, int k) {
        // Complete the function
        int n = a.size(), res = 0;
        
        unordered_map<int, int> pre;
        pre[0] = -1;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum = ((sum + a[i]) % k + k) % k;
            
            if (pre.find(sum) != pre.end()){
                res = max(res, i - pre[sum]);
            } else {
                pre[sum] = i;
            }
        }
        
        return res;
    }
};
