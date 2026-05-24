class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        for (int l = 0; l < n; l += k) {
            int st = l;
            int en = min(n - 1, l + k - 1);
            
            while (st < en) {
                arr[st] = arr[st] ^ arr[en];
                arr[en] = arr[st] ^ arr[en];
                arr[st] = arr[st] ^ arr[en];
                st++;
                en--;
            }
        }
    }
};
