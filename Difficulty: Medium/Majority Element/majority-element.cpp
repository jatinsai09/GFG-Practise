class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = arr[0], c = 1;
        
        for (int i = 1; i < n; i++) {
            if (c == 0) {
                res = arr[i];
            }
            
            c += (res == arr[i] ? 1 : -1);
        }
        
        c = 0;
        for (auto &i: arr) {
            c += (i == res);
        }
        
        return (c > n / 2 ? res : -1);
    }
};