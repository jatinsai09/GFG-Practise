

class Solution {
  public:
    string smallestNumber(string N) {
        // code here.
        int n = N.size();
        vector<int> last(10, -1);

        for (int i = 0; i < n; i++) {
            last[N[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++) {
            int cur = N[i] - '0';

            for (int d = 0; d < cur; d++) {
                if (i == 0 && d == 0) {
                    continue;
                }
                if (last[d] > i) {
                    swap(N[i], N[last[d]]);
                    return N;
                }
            }
        }

        return N;
    }
};