class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        set<string> vis1, vis2;
        
        for (auto &s: arr) {
            vis1.insert(s);
        }
        
        vector<string> res;
        for (auto &s: arr) {
            if (!vis2.count(s)) {
                res.push_back(s);
                vis1.insert(s);
                vis2.insert(s);
                continue;
            }
            
            int x = 1;
            while (vis1.count(s + to_string(x))) {
                x++;
            }
            
            string got = s + to_string(x);
            vis1.insert(got);
            vis2.insert(got);
            
            res.push_back(got);
        }
        
        return res;
    }
};