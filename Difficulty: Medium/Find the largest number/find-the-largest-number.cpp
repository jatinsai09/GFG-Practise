class Solution {
  public:

    int find(int N) {
        // code here
        string s = to_string(N);
        int n = s.size();
        
        for (int i = n - 1; i > 0; i--) {
            if (s[i] < s[i - 1]) {
                s[i - 1]--;
                for (int j = i; j < n; j++) {
                    s[j] = '9';
                }
            }
        }
       
        
        return stoi(s);
    }
};