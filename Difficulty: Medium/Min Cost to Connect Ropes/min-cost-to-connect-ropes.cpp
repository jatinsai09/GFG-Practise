class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if (arr.size() <= 1) {
            return 0;
        }

        priority_queue<long long, vector<long long>, greater<>> pq;
        for (const auto& x : arr) {
            pq.push(x);
        }

        long long cost = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            
            cost += a + b;
            pq.push(a + b);
        }
        return cost;
    }
};