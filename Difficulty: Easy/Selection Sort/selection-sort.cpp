class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &a) {
        // code here
        int n = a.size();
        
        for (int i = 0; i < n - 1; i++) {
            int mini = i;
            for (int j = i + 1; j < n; j++) {
                if (a[mini] > a[j]) {
                    mini = j;
                }
            }
            if (i != mini) {
                swap(a[i], a[mini]);
            }
        }
    }
};