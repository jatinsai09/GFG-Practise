class Solution {
  public:
    int cntWays(vector<int>& nums) {
        // code here
        int n = nums.size();
        vector<int> po(n + 2), pe(n + 2), so(n + 2), se(n + 2);
        
        for (int i = 1; i <= n; i++) {
            po[i] = po[i - 1];
            pe[i] = pe[i - 1];
            if ((i - 1) & 1) {
                po[i] += nums[i - 1];
            } else {
                pe[i] += nums[i - 1];
            }
        }
        
        for (int i = n; i > 0; i--) {
            so[i] = so[i + 1];
            se[i] = se[i + 1];
            if ((i - 1) & 1) {
                so[i] += nums[i - 1];
            } else {
                se[i] += nums[i - 1];
            }
        }
        
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (po[i - 1] + se[i + 1] == pe[i - 1] + so[i + 1]) {
                c++;
            }
        }
        
        return c;
    }
};