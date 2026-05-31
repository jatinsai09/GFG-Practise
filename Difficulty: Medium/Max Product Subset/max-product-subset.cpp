class Solution {
const int mod = 1e9 + 7;
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 1) {
            return arr[0];
        }
        
        int c0 = 0, neg = 0, ind = -1, mn = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                c0++;
            } else if (arr[i] < 0) {
                neg++;
                if (arr[i] > mn) {
                    ind = i;
                    mn = arr[i];
                }
            }
        }
        
        if (c0 == n) {
            return 0;
        }
        if (c0 == n - 1 && neg == 1) {
            return 0;
        } 
        
        long long res = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                continue;
            }
            if (neg % 2 == 1 && i == ind) {
                continue;
            }
            res = ((res * arr[i]) % mod + mod) % mod;
        }
        
        return res;
    }
};
