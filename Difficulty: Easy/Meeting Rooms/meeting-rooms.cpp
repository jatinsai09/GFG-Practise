// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        for(int i = 1;i < n; i++){
            if(arr[i - 1][1] > arr[i][0]){
                return false;
            }
        }
        
        return true;
    }
};
