class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res(n, -1);
        
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        res[k - 1] = pq.top();
        
        for (int i = k; i < n; i++) {
            pq.push(arr[i]);
            pq.pop();
            
            res[i] = pq.top();
        }
        
        return res;
    }
};