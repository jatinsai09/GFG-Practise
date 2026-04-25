class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            bool can = true;
            while (!res.empty() && (res.back() < 0) != (arr[i] < 0)) {
                if (abs(arr[i]) < abs(res.back())) {
                    can = false;
                    break;
                } else if (abs(arr[i]) == abs(res.back())) {
                    can = false;
                    res.pop_back();
                    break;
                } else {
                    res.pop_back();
                }
            }
            
            if (can) {
                res.push_back(arr[i]);
            }
        }
        
        return res;
    }
};