class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &a, vector<int> &b,
                               vector<int> &c) {
        // Code Here
        int n1 = a.size(), n2 = b.size(), n3 = c.size();
        
        int i = 0, j = 0, k = 0;
        vector<int> res;

        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                res.push_back(a[i]);
                int x = a[i];

                while (i < n1 && a[i] == x) i++;
                while (j < n2 && b[j] == x) j++;
                while (k < n3 && c[k] == x) k++;
            } else if (a[i] < b[j]) {
                i++;
            } else if (b[j] < c[k]) {
                j++;
            } else {
                k++;
            }
        }
        
        if (res.empty()) {
            return {-1};
        }
        
        return res;
    }
};