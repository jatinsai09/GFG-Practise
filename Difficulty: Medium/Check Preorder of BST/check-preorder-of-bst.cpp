class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        stack<int> st;
        int lowerBound = INT_MIN;

        for (const auto& i : arr) {
            if (i < lowerBound) {
                return false;
            }

            while (!st.empty() && i > st.top()) {
                lowerBound = st.top();
                st.pop();
            }

            st.push(i);
        }

        return true;
    }
};