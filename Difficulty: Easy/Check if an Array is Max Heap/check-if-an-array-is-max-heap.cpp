class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] > arr[(i - 1) / 2]) {
                return false;
            }
        }
        
        return true;
    }
};
