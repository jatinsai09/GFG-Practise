// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int mx = arr[0], mn = arr[0], res = arr[0];

        for(int i = 1; i < n; i++){
            int x = arr[i];

            if(x < 0){
                swap(mx, mn);
            }

            mx = max(x, mx * x);
            mn = min(x, mn * x);

            res = max(res, mx);
        }

        return res;
        // Your Code Here
    }
};
