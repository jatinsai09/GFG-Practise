class Solution {
#define ll long long int
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        ll n = arr.size(), res = 0;
        for (int i = 0; i < 32; i++) {
            int c1 = 0;
            for (auto &a: arr) {
                c1 += ((a >> i) & 1);
            }
            res += c1 * (n - c1) * (1LL << i);
        }
        return res;
    }
};