
class Solution {
  public:
    int findMaxSum(vector<int>& a) {
        // code here
        int n = a.size();
        int l = a[0], sl = 0, res = a[0];
        
        for(int i = 1; i < n; i++){
            res = max(sl + a[i], l);
            
            sl = l;
            l = res;
        }
        return l;
    }
};

