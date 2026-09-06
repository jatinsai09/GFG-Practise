class Solution {
#define ll long long int
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        ll res = 0;
        
        vector<int> f(32);
        for (const auto &i: arr) {
            for (int b = 0; b < 32; b++) {
                if ((i >> b) & 1) {
                    res += (1LL << b) * f[b];
                    f[b]++;
                }
            }
        }
        
        return res;
    }
};