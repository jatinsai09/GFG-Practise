class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        
        int i = n1 - 1, j = n2 - 1, k = n3 - 1;
        int g1 = 0, g2 = 0, g3 = 0, res = 0;
        while(max({i, j, k}) >= 0) {
            int mn = min({g1, g2, g3});
            
            if (g1 == mn) {
                if (i < 0) {
                    break;
                }
                g1 += s1[i--];
            }
            if (g2 == mn)  {
                if (j < 0) {
                    break;
                }
                g2 += s2[j--];
            }
            if (g3 == mn) {
                if (k < 0) {
                    break;
                }
                g3 += s3[k--];
            }
            
            if (g1 == g2 && g2 == g3) {
                res = max(res, g1);
            }
        }
        return res;
    }
};