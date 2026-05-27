
class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        res.push_back(arr[0]);
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > res.back()) {
                res.push_back(arr[i]);
            }
            else {
                int ind = lower_bound(begin(res), end(res), arr[i]) - begin(res);
                res[ind] = arr[i];
            }
        }
        return res.size();
    }
};

