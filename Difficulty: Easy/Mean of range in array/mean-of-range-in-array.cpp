class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
          int n = arr.size();
          vector<int> ps(n, 0);
          ps[0] = arr[0];
          
          for(int i = 1; i < n; i++){
              ps[i] = ps[i - 1] + arr[i];
          } 
          
          
          vector<int> res;
          
          for(auto& q: queries){
            int l = q[0], r = q[1];
            int len = r - l + 1;
            int sum = ps[r] - (l > 0 ? ps[l - 1] : 0);
            
            int got = sum / (1.0 * len);
            res.push_back(got);
          }
          
          return res;
    }
};