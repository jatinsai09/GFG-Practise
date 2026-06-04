// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string s, int k) {
        // code here
        int n = s.size();
        if (n & (n - 1)) {
            k <<= 1;
        } else {
            k >>= 1;
        }
        
        if (k >= n) {
            return "-1";
        } 
        
        string res;
        
        for (int i = 0; i < n; i++) {
            while (k > 0 && !res.empty() && res.back() > s[i]) {
                res.pop_back();
                k--;
            }
            res.push_back(s[i]);
        }
        
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        
        return res;
    }
};