// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        int dpp[1011][1011];
        memset(dpp, -1, sizeof(dpp));
        // code here
        
        auto help = [&](auto&& f, int i, int cap) -> int{
            if(!i){
                return (cap / wt[i]) * val[i];
            }
            if(dpp[i][cap] != -1){
                return dpp[i][cap];
            }
            
            int notTake = f(f, i - 1, cap);
            int take = INT_MIN;
            if(wt[i] <= cap){
                take = val[i] + f(f, i, cap - wt[i]);
            }
            
            return dpp[i][cap] = max(take, notTake);
        };
        
        return help(help, n - 1, capacity);
    }
};