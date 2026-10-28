class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        int res = 0;
        
        multiset<int> st;
        for (auto &i: files) {
            st.insert(i);
        }
        
        while (st.size() > 1) {
            int a = *st.begin();
            st.erase(begin(st));
            
            int b = *st.begin();
            st.erase(begin(st));
            
            res += a + b;
            
            st.insert(a + b);
        }
        return res;
    }
};