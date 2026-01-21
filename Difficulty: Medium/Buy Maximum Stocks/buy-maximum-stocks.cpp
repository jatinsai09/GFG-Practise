class Solution {
  public:
    int buyMaximumProducts(int n, int k, int prices[]) {
        // Write your code here
        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++){
            vp.push_back({prices[i], i + 1});
        }
        sort(begin(vp), end(vp));
        
        int res = 0;
        for(int i = 0; i < n; i++){
            int price = vp[i].first, can = k / price;
            int got = min(can, vp[i].second);
            
            res += got;
            k -= price * got;
        }
        
        return res;
    }
};
