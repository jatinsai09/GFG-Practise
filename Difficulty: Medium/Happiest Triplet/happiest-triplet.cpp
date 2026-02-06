class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        int bestDiff = INT_MAX, bestSum = INT_MAX;
        vector<int> ans(3);

        while (i < n && j < n && k < n) {
            int x = a[i], y = b[j], z = c[k];
            int mx = max(x, max(y, z));
            int mn = min(x, min(y, z));
            int diff = mx - mn, sum = x + y + z;

            if ((diff < bestDiff) || (diff == bestDiff && sum < bestSum)) {
                bestDiff = diff;
                bestSum = sum;
                ans = {x, y, z};
            }

            if (mn == x) {
                i++;
            } else if (mn == y) {
                j++;
            } else {
                k++;
            }
        }

        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};