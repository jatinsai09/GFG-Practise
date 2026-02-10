class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int l = 1, r = *max_element(begin(arr),end(arr));
        
        auto check = [&](int m){
            int c = 0;
            for(auto& i:arr){
                c += (i + m - 1) / m;
            }
            return c <= k;
        };
        
        while(l <= r){
            int mid = (l + r) >> 1;
            
            if(check(mid)){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return l;
    }
};