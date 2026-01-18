// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int res = 0;
        
        for (int b = 20; b >= 0; b--) {
            int req  = res | (1 << b);
            unordered_set<int> st;
            
            for (auto &i : arr) {
                int got = (i >> b);
                st.insert(got << b);
            }
            
            for (auto &i: arr) {
                int got = (i >> b);
                int x = (got << b);
                
                if (st.count(x ^ req)) {
                    res = req;
                    break;
                }
            }
        }
        
        return res;
    }
};
