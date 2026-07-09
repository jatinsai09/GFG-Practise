class Solution {
  public:
    int countKdivPairs(vector<int>& a, int k) {
        // code here
        int n = a.size();
        vector<int> f(k);
        
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int rem = a[i] % k;
            
            res += (!rem ? f[rem] : f[k - rem]);
            f[rem]++;
        }
        return res;
    }
};