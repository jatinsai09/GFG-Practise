class Solution {
  public:
    vector<int> twoRepeated(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            
            if (arr[idx] < 0) {
                res.push_back(abs(arr[i]));
            } else {
                arr[idx] *= -1; 
            }
        }
        
        return res;
    }
};
