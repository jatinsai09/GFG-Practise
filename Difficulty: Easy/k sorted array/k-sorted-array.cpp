// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            if (abs(v[i].second - i) > k) {
                return "No";
            }
        }

        return "Yes";
    }
};