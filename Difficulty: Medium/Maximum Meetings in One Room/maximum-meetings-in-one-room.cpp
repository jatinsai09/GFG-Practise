// User function Template for C++

class Solution {
  public:
    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f) {
        vector<int> ind(n), res;
        
        for (int i = 0; i < n; i++) {
            ind[i] = i;
        }
        
        sort(begin(ind), end(ind), [&](auto& i, auto& j){
           if (f[i] != f[j]) {
               return f[i] < f[j];
           } 
           return s[i] < s[j];
        });
        
        int e = f[ind[0]];
        res.push_back(ind[0] + 1);
        for (int i = 1; i < n; i++) {
            if (s[ind[i]] > e) {
                res.push_back(ind[i] + 1);
                e = f[ind[i]];
            }
        }
        
        sort(begin(res), end(res));
        
        return res;
    }
};