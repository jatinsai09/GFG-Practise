class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string res = "";
        
        for (auto& c: s) {
            if (c == ' ') {
                continue;
            }
            res += c;
        }
        
        return res;
    }
};