class Solution {
#define pii pair<int, int>
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(rbegin(a), rend(a));
        sort(rbegin(b), rend(b));
        
        int n = a.size();
        
        priority_queue<pii> pq;
        for (int i = 0; i < n; i++) {
            pq.push({a[i] + b[0], 0});
        }
        
        vector<int> res;
        while (!pq.empty() && k > 0) {
            auto [s, ind] = pq.top();
            pq.pop();
            
            res.push_back(s);
            k--;
            
            if (ind + 1 < n) {
                pq.push({s - b[ind] + b[ind + 1], ind + 1});
            }
        }
        
        return res;
    }
};