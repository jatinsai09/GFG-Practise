class Solution {
  public:
    vector<int> countBSTs(vector<int>& a) {
        // Code here
        int n = a.size();

        vector<int> b = a;
        sort(b.begin(), b.end());

        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++)
        {
            pos[b[i]] = i;
        }

        vector<int> cat(n + 1, 0);
        cat[0] = 1;
        cat[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                cat[i] += (cat[j] * cat[i - j - 1]);
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            int l = pos[a[i]];
            int r = n - l - 1;

            ans[i] = cat[l] * cat[r];
        }

        return ans;
    }
};