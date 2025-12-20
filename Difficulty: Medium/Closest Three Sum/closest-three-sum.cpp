// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> a, int target) {
        // Your code goes here
        sort(begin(a), end(a));
        int n = a.size(), res = INT_MIN, mn = INT_MAX;
        
        for (int i = 0; i + 2 < n; i++) {
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                int sum = a[i] + a[j] + a[k], del = abs(sum - target);
                
                if (del < mn) {
                    res = sum;
                    mn = del;
                } else if (del == mn) {
                    res = max(res, sum);
                }
                
                if (sum < target) {
                    j++; 
                } else {
                    k--;
                }
            }
        }
        
        return res;
    }
};
