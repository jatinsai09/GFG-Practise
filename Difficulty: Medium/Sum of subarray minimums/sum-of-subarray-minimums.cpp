class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> l(n), r(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                l[i] = i + 1;
            }
            else {
                l[i] = i - st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                r[i] = n - i;
            }
            else {
                r[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += (long long)arr[i] * l[i] * r[i];
        }
        
        return ans;
    }
};