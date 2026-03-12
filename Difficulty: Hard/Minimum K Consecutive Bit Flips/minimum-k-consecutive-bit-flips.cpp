class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> mark(n,0);
        int flip = 0, ans = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k) {
                flip ^= mark[i-k];
            }

            if((arr[i] ^ flip) == 0) {
                if(i + k > n) return -1;

                ans++;
                flip ^= 1;
                mark[i] = 1;
            }
        }

        return ans;
    }
};