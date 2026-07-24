class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size(), m = s2.size();
        int bestLen = 1e9, bestL = -1;

        for (int i = 0; i < n; i++) {
            if (i <= bestL) {
                continue;
            }
            
            int j = 0, k = i;
            while (k < n && j < m) {
                j += (s1[k] == s2[j]);
                k++;
            }

            if (j == m) {
                int end = k - 1, start = end, j = m - 1;

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
