

class Solution {
  public:
    int minMoves(vector<int>& arr, int k) {
        // write code here
        const long long MOD = 1000000007;
        long long res = 0;
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                long long diff = arr[i] - arr[i - 1], ops = (diff + k - 1) / k;
                res = (res + ops) % MOD;
                arr[i] -= ops * k;
            }
        }
        
        return res;
    }
};