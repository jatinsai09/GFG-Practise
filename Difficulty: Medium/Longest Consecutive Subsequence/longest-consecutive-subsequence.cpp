class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st;
        for (auto &i: arr) {
            st.insert(i);
        }
        
        int res = 0;
        for (auto &i: arr) {
            if (st.find(i - 1) == st.end()) {
                int cur = i, c = 0;
                while (st.find(cur) != st.end()) {
                    cur++;
                    c++;
                }
                res = max(res, c);
            }
        }
        
        return res;
    }
};