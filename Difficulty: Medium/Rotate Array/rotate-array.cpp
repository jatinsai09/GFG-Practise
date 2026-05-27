class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d %= n;
        
        vector<int> t;
        for(int i = 0; i < d; i++){
            t.push_back(arr[i]);
        }
        
        for(int i = d; i < n; i++) {
            arr[i - d] = arr[i];
        }
        for(int i = n - 1; i >= n - d; i--) {
            arr[i] = t.back();
            t.pop_back();
        }
    }
};
