
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        
        vector<vector<int>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i] = {finish[i], start[i]};
        }
        sort(begin(vp), end(vp));
        
        int res = 0, ft = -1;
        for(auto& v : vp){
            if(v[1] > ft){
                res++;
                ft=v[0];
            }
        }
        
        return res;
    }
};

