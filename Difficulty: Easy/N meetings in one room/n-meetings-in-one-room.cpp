class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = end.size();
        vector<pair<int, int>> vp;
        
        for (int i = 0; i < n; i++) {
            pair<int, int> p = make_pair(start[i], end[i]);
            vp.push_back(p);
        }
        sort(vp.begin(), vp.end(), cmp);
        
        int c = 1, prev = vp[0].second;
        for (int i = 1; i < n; i++) {
            if (vp[i].first > prev) {
                c++;
                prev = vp[i].second;
            }
        }
        return c;
    }
};