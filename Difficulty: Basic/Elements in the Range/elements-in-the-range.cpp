class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int c = 0;
        for (auto &i: arr) {
            if (i >= start && i <= end) {
                c++;
            } 
        }
        return c == end - start + 1;
    }
};
