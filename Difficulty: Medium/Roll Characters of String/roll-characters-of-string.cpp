class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n = s.size();
        vector<int> inc(n);
        
        for (auto &ind: roll) {
            inc[ind - 1]++;
        }
        for (int i = n - 2; i >= 0; i--) {
            inc[i] += inc[i + 1];
        }
        
        for (int i = 0; i < n; i++) {
            int sft = inc[i] % 26;
            
            int og = s[i] - 'a', nxt = (og + sft) % 26;
            
            s[i] = char('a' + nxt);
        }
        return s;
    }
};
