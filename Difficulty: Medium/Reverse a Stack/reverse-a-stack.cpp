class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        stack<int> t;
        
        while (!st.empty()) {
            t.push(st.top());
            st.pop();
        }
        
        st = t;
    }
};