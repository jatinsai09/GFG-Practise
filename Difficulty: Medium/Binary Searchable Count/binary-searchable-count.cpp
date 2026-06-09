class Solution {
  public:
    bool binarySearch(vector<int>& arr, int st, int en, int& val) {
        if (st > en) {
            return false;
        }
        
        int mid = (st + en) / 2;
        if (arr[mid] == val) {
            return true;
        }
        
        if (val < arr[mid]) {
            return binarySearch(arr, st, mid - 1, val);
        } else {
            return binarySearch(arr, mid + 1, en, val);
        }
        
    }
    int binarySearchable(vector<int>& arr) {
        // code here
        int res = 0;
        for (auto &it : arr) {
            if (binarySearch(arr, 0, arr.size() - 1, it)) {
                res++;
            }
        }
        return res;
    }
};