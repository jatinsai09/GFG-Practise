class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> freq(26, 0);
        queue<char> q;
        string res = "";
        
        for (auto& ch : s) {
            freq[ch - 'a']++;
            q.push(ch);
        
            // Remove repeating characters from the front
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
        
            res += (q.empty() ? '#' : q.front());
        }
        
        return res;
    }
};