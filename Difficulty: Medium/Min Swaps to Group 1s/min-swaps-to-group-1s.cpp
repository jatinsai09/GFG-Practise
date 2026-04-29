class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size(), c1 = 0;
        for (auto &i : arr) {
            c1 += i;
        }
        
        if (c1 == 0) {
            return -1;
        }
        
        int mx = 0, cur = 0;
        for (int i = 0; i < c1; i++) {
            cur += arr[i];
        }
        mx = cur;
        
        for (int i = c1; i < n; i++) {
            cur -= arr[i - c1];
            cur += arr[i];
            
            mx = max(mx, cur);
        }
        
        return c1 - mx;
    }
};