class Solution {
  public:
    int f(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        
        int area = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] > a[i]) {
                int h = a[st.top()];
                st.pop();
                
                int pse = (st.empty() ? -1 : st.top());
                int nse = i;
                
                int got = h * (nse - pse - 1);
                area = max(area, got);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int h = a[st.top()];
            st.pop();
            
            int pse = (st.empty() ? -1 : st.top());
            int nse = n;
            
            int got = h * (nse - pse - 1);
            area = max(area, got);
        }
        return area;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                mat[i][j] += mat[i - 1][j];
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, f(mat[i]));
        }
        
        return res;
    }
};