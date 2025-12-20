class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int n1 = arr1.size(), n2 = arr2.size(), i = 0, j = 0;
        long long s1 = 0, s2 = 0, res = 0;
        
        while (i < n1 && j < n2) {
            if (arr1[i] == arr2[j]) {
                res += max(s1, s2) + arr1[i];
                s1 = s2 = 0;
                i++;
                j++;
            } else if (arr1[i] < arr2[j]) {
                s1 += arr1[i++];
            } else {
                s2 += arr2[j++];
            }
        }
        
        while (i < n1) {
            s1 += arr1[i++];
        }
        while (j < n2) {
            s2 += arr2[j++];
        }
        
        res += max(s1, s2);
        
        return res;
    }
};