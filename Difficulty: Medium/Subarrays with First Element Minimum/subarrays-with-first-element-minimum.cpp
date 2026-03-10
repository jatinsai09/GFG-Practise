class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        long long res = 0;

        for(int i = n - 1, j; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            j = (st.empty() ? n : st.top());

            res += (j - i);
            st.push(i);
        }

        return res;
    }
};