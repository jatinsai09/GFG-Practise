class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> a, int n, int k) {
        // your code here
        vector<int> res;
        deque<int> dq;
        
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && a[dq.back()] < a[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(a[dq.front()]);
        
        for (int i = k; i < n; i++) {
            while (!dq.empty() && a[dq.back()] < a[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            res.push_back(a[dq.front()]);
        }
        
        return res;
    }
};