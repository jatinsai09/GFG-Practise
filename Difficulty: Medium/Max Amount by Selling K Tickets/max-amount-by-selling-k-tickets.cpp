class Solution {
const int mod = 1e9 + 7;
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        priority_queue<int> pq;
        for (auto &i: arr) {
            pq.push(i);
        }
        
        long long res = 0;
        
        while (k-- && !pq.empty()) {
            int x = pq.top();
            pq.pop();
            
            res = (res + x) % mod;
            if (x > 1) {
                pq.push(x - 1);
            }
        }
        
        return res;
        
    }
};