// User function Template for C++

class Solution {
  public:
    string kthPermutation(int n, int k) {
        // code here
        vector<int> nums;
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        
        vector<int> fact(n);
        fact[0] = 1;
        for(int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        
        k--;
        string res = "";
        
        for (int i = n; i >= 1; i--) {
            int ind = k / fact[i - 1];
            
            res += to_string(nums[ind]);
            nums.erase(begin(nums) + ind);
            
            k %= fact[i - 1];
        }
        
        return res;
    }
};