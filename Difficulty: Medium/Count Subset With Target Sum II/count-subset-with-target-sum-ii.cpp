class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int mid = n / 2;
        
        vector<long long> left, right;
        
        for (int mask = 0; mask < (1 << mid); mask++) {
            long long sum = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i)) {
                    sum += arr[i];
                }
            }
            left.push_back(sum);
        }
        
        for (int mask = 0; mask < (1 << (n - mid)); mask++) {
            long long sum = 0;
            for (int i = 0; i < n - mid; i++) {
                if (mask & (1 << i)) {
                    sum += arr[mid + i];
                }
            }
            right.push_back(sum);
        }
        
        sort(right.begin(), right.end());
        
        int ans = 0;
        for (long long x : left) {
            long long need = k - x;
            ans += upper_bound(right.begin(), right.end(), need)
                 - lower_bound(right.begin(), right.end(), need);
        }
        
        return ans;
    }
};