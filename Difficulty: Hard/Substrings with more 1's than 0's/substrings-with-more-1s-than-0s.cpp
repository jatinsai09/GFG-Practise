class Solution {
  public:
    int countSubstring(string& s) {
        // Code Here
        int n = s.size();
        vector<int> f(2 * n + 2), pf(f);
        
        int sum = 0, res = 0;
        int off = n + 1;
        f[off] = pf[off] = 1;
        for (auto &i: s) {
            sum += (i == '1' ? 1 : -1);
            
            res += pf[sum + off - 1];
            
            pf[sum + off] = ++f[sum + off] + 
                        pf[sum + off - 1];
        }
        return res;
    }
};