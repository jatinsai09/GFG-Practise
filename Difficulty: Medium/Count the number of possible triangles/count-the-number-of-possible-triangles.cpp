class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size(), cnt = 0;
        sort(begin(arr), end(arr));
        
        for (int i = n - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] > arr[i]) {
                    cnt += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        return cnt;
    }
};
