class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& a, int k) {
        // code here
       int n = a.size();
       vector<int> res;
       deque<int> dq;
       
       for (int i = 0; i < k; i++) {
           while (!dq.empty() && a[dq.back()] <= a[i]) {
               dq.pop_back();
           }
           dq.push_back(i);
       }
       
       res.push_back(a[dq.front()]);
       for (int i = k; i < n; i++) {
           if (dq.front() <= i - k) {
               dq.pop_front();
           }
           
           while (!dq.empty() && a[dq.back()] <= a[i]) {
               dq.pop_back();
           }
           dq.push_back(i);
           
           res.push_back(a[dq.front()]);
       }
       
       return res;
    }
};