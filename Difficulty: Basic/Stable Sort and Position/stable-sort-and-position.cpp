//Back-end complete function template in C++

class Solution {

  public:
    // Function to get the index of an element in a sorted array.
    int getIndexInSortedArray(vector<int>& arr, int k) {
        // Write Code Here
        int n = arr.size(), x = arr[k], pos = 0;
        
        
        for (int i = 0; i < n; i++) {
            if (arr[i] < x) {
                pos++;
            } else if(arr[i] == x && i < k) {
                pos++;
            }
        }
        
        return pos;
    }
};