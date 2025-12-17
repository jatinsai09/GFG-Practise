class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int h = 1, v = 1;
        long long cost = 0;

        while (i < x.size() && j < y.size()) {
            if (x[i] > y[j]) {
                cost += (long long)x[i] * h;
                v++;
                i++;
            } else {
                cost += (long long)y[j] * v;
                h++;
                j++;
            }
        }

        while (i < x.size()) {
            cost += (long long)x[i] * h;
            i++;
        }

        while (j < y.size()) {
            cost += (long long)y[j] * v;
            j++;
        }

        return cost;
    }
};
