class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        map<int, int> f;
        for (auto &i: arr) {
            f[i]++;
        }
        
        vector<pair<int, int>> vp;
        for (auto &i: arr) {
            vp.push_back({-f[i], i});
        }
        
        sort(begin(vp), end(vp));
        
        for (int i = 0; i < n; i++) {
            arr[i] = vp[i].second;
        }
        
        return arr;
    }
};