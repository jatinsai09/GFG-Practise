class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        int n = s.size(), mx = 0;
        unordered_map<char, int> f;
        for (auto &c: s) {
            f[c]++;
            mx = max(mx, f[c]);
        }
        
        if (mx > (n + 1) / 2) {
            return "";
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto &[key, val]: f) {
            pq.push({val, key});
        }
        
        string res = "";
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top();
            pq.pop();
            auto [f2, c2] = pq.top();
            pq.pop();
            
            res += c1;
            res += c2;
            
            if (f1 > 1) {
                pq.push({f1 - 1, c1});
            }
            if (f2 > 1) {
                pq.push({f2 - 1, c2});
            }
        }
        
        if (!pq.empty()) {
            auto [f1, c] = pq.top();
            if (f1 == 1) {
                res += c;
            } else {
                return "";
            }
        }
        
        return res;
    }
};