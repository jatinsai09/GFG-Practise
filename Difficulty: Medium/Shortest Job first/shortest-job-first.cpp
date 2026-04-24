// User function Template for C++

//Back-end complete function Template for C++

class Solution {
#define ll long long
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(begin(bt), end(bt));
        ll n = bt.size(), sum = 0, ps = 0;
        
        for (auto &i: bt) {
            sum += ps;
            ps += i;
        }
        return sum / n;
    }
};