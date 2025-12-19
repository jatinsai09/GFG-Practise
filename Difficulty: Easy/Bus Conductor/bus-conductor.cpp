class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(begin(chairs), end(chairs));
        sort(begin(passengers), end(passengers));
        int n = chairs.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            res += abs(chairs[i] - passengers[i]);
        }
        
        return res;
    }
};