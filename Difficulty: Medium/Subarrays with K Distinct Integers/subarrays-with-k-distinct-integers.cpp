class Solution {
  public:
    int exactlyK(vector<int> &a, int k) {
        // code here
        int n = a.size();
        
        auto atmost = [&](int k){
            unordered_map<int, int> cnt;
            int res = 0, i = 0;
            
            for(int j = 0;j < n; j++){
                if(++cnt[a[j]] == 1){
                    k--;
                }
                
                while(k < 0){
                    if(--cnt[a[i]] == 0){
                        k++;
                    }
                    i++;
                }
                res += (j - i + 1);
            }
            return res;
        };
        
        return atmost(k) - atmost(k - 1);
    }
};
