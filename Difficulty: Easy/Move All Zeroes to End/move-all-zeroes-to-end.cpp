class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int l = 0, c = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            if(!arr[i]){
                c++;
            } else {
                arr[l++] = arr[i];
            }
        }
        
        for(int i = n - 1; i >= n - c; i--){
            arr[i] = 0;
        }
    }
};