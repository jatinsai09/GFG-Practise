class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        auto can = [&](double m) {
            int need = 0;
            for (int i = 1; i < n; i++) {
                int dist = stations[i] - stations[i - 1];
                
                int req = dist / m;
                if (req * m < dist) {
                    req++;
                }
                
                need += req - 1;
                
                if (need > k) {
                    return false;
                }
            }
            
            return true;
        };
        
        double l = 0, r = stations[n - 1] - stations[0], m;
        while (r - l > 1e-6){
            m = (l + r) / 2.0;
            
            if (can(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};