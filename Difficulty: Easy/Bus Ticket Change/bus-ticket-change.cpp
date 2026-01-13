class Solution {
  public:
    bool canServe(vector<int> &a) {
        // code here
        int n = a.size(), c5 = 0, c10 = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 5) {
                c5++;
            } else if (a[i] == 10) {
                if (c5) {
                    c5--;
                } else {
                    return false;
                }
                c10++;
            } else {
                if (c5 && c10) {
                    c5--;
                    c10--;
                } else if (c5 >= 3) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};