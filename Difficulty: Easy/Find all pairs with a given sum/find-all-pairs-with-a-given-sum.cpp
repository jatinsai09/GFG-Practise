class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
        // Code here
        vector<pair<int, int>> res;
        sort(begin(arr1), end(arr1));
        sort(begin(arr2), end(arr2));
        
        int n = arr1.size(), m = arr2.size(), i = 0, j = m - 1;
        
        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                int e1 = arr1[i], e2 = arr2[j], c1 = 0, c2 = 0;
                while (i < n && arr1[i] == e1) {
                    c1++;
                    i++;
                }
                while (j >= 0 && arr2[j] == e2) {
                    c2++;
                    j--;
                }
                
                for (int k = 0; k < c1 * c2; k++) {
                    res.push_back({e1, e2});
                }
            }
        }
        
        return res;
    }
};