class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int ind = abs(arr[i]) - 1;
            
            if (arr[ind] > 0) {
                arr[ind] *= -1;
            } else {
                res.push_back(abs(arr[i]));
            }
        }
        return res;
    }
};