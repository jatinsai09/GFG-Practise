// User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        // code here
        vector<int> lis = {h[0]};
        
        for (int i = 1; i < n; i++) {
            if (h[i] > lis.back()) {
                lis.push_back(h[i]);
            } else {
                int ind = lower_bound(begin(lis), end(lis), h[i]) - begin(lis);
                lis[ind] = h[i];
            }
        }
        
        return n - lis.size();
    }
};