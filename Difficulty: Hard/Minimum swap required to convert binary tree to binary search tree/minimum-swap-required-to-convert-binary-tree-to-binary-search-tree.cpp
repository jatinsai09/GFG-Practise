// User function Template for C++
class Solution {
  public:
    void dfs(int i, vector<int>& a, vector<int>& b) {
        if(i >= a.size()) {
            return;
        }
        dfs(2*i + 1, a, b);
        b.push_back(a[i]);
        dfs(2*i + 2, a, b);
    }

    int minSwaps(vector<int>& a) {
        vector<int> b;
        dfs(0, a, b);

        int n = b.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {b[i], i};
        }
        sort(v.begin(), v.end());

        vector<int> vis(n, 0);
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] || v[i].second == i) {
                continue;
            }
            
            int c = 0, j = i;
            while(!vis[j]) {
                vis[j] = 1;
                j = v[j].second;
                c++;
            }
            res += c - 1;
        }
        return res;
    }
};