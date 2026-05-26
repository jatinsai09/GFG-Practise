// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size(), flag = 0;
        for(int i = n-1; i > 0; i--){
            if(arr[i] > arr[i - 1]){
                int ind; 
                for(ind = n - 1; ind >= i; ind--){
                    if(arr[ind] > arr[i - 1]){
                        break;
                    }
                }
                swap(arr[i - 1], arr[ind]);
                flag = 1;
                sort(begin(arr) + i, end(arr));
                break;
            }
        }
        if(!flag){
            sort(begin(arr), end(arr));
        }
    }
};
