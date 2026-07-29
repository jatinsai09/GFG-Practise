class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        set<int> st;
        int res = 0;
        for (const auto& i: arr) {
            st.insert(i);
        }
        
        for (const auto& i: arr) {
            if (st.count(i - 1)) {
                continue;
            }
            
            res++;
        }
        return res;
    }
};
