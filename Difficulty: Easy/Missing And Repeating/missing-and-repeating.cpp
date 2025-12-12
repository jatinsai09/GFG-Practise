class Solution {
#define ll long long int    
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        ll n = (ll)arr.size();
        ll s = 0, sq = 0;
        for (auto &i: arr) {
            s += i;
            sq += 1LL * i * i;
        }
        
        ll s_n = n * (n + 1) / 2;
        ll sq_n = n * (n + 1) * (2 * n + 1) / 6;
        
        ll sub = s - s_n;
        ll add = (sq - sq_n) / sub;
        
        return {(int)(add + sub) / 2, (int)(add - (add + sub) / 2)};
    }
};