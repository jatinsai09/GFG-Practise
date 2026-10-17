class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        
        if (n != m) {
            return false;
        }
        
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (s1[i] == '#') {
                i++;
                continue;
            }
            if (s2[j] == '#') {
                j++;
                continue;
            }
            
            if (s1[i] != s2[j]) {
                return false;
            }
            
            if (s1[i] == 'A' && i < j) {
                return false;
            }
            if (s1[i] == 'B' && i > j) {
                return false;
            }
            
            i++;
            j++;
        }
        return true;
    }
};