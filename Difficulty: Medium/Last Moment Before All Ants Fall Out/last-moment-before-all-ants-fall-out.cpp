class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int rend = n, lend = 0, mx = 0;
        for(auto& ind: left){
            mx = max(mx, ind - lend);
        }
        
        for(auto& ind: right){
            mx = max(mx, rend - ind);
        }
        return mx;
    }
};