class Solution {
  public:
    int find_height(int tree[], int n, int k) {
        // code here
        int low = 0, high = 0;

        for (int i = 0; i < n; i++) {
            high = max(high, tree[i]);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long wood = 0;
            
            for (int i = 0; i < n; i++) {
                if (mid < tree[i]) {
                    wood += (tree[i] - mid);
                }
            }
            
            if (wood == k) {
                return mid;
            }
            
            if (wood > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};