class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        int bestLen = 1e9;
        int bestL = -1;

        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = i;

            while (k < n && j < m) {
                if (s1[k] == s2[j]) {
                    j++;
                }
                k++;
            }

            if (j == m) {
                int end = k - 1;
                j = m - 1;
                int start = end;

                while (start >= i) {
                    if (s1[start] == s2[j]) {
                        j--;
                        if (j < 0) {
                            break;
                        }
                    }
                    start--;
                }

                int len = end - start + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestL = start;
                }
            }
        }

        if (bestL == -1) {
            return "";
        }
        return s1.substr(bestL, bestLen);
    }
};
