class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        // code here
        int n = s1.size();
        
        if (n != s2.size()) {
            return false;
        }
        
        if (n <= 2) {
            return s1 == s2;
        }
        
        string clockwise = s1.substr(n - 2) + s1.substr(0, n - 2);
        string anticlockwise = s1.substr(2) + s1.substr(0, 2);
        
        return (s2 == clockwise || s2 == anticlockwise);
    }
};
