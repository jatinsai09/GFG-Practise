class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size(), res = 0;
        vector<int> gain;
        for (int i = 0; i < n; i++) {
            res += a[i];
            gain.push_back(b[i] - a[i]);
        }
        sort(rbegin(gain), rend(gain));
        
        int ta = n, tb = 0;
        for (int i = 0; i < n; i++) {
            if (tb < y && gain[i] > 0) {
                res += gain[i];
                ta--;
                tb++;
            } else if (ta > x) {
                res += gain[i];
                ta--;
                tb++;
            }
        }
        return res;
    }
};