class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()] <= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                res[i] = i + 1;
            }
            else{
                res[i] = i - st.top();
            }
            st.push(i);
        }
        
        return res;
    }
};
