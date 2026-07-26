class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        double l = 0, r = 0, m;
        for (int i = 1; i < n; i++) {
            double dist = stations[i] - stations[i - 1];
            
            r = max(r, dist);
        }
        
        auto can = [&](double m) {
            int need = 0;
            for (int i = 1; i < n; i++) {
                int dist = stations[i] - stations[i - 1];
                
                int req = dist / m;
                
                if (dist == m * req) {
                    req--;
                }
                need += req;
                
                if (need > k) {
                    return false;
                }
            }
            
            return true;
        };
        
        double df = 1e-6;
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