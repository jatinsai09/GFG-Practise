class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size(), i = 0, j = 0, res = 0;
        
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') {
                i++;
            }
            while (j < n && arr[j] != 'T') {
                j++;
            }
            
            if (i < n && j < n) {
                if (abs(i - j) <= k) {
                    res++;
                    i++;
                    j++;
                } else if (i < j) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        
        return res;
    }
};