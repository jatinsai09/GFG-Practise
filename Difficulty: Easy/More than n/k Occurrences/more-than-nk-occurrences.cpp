class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Your code here
        int n = arr.size();
        unordered_map<int, int> mp;

        for (const auto& a: arr) {
            mp[a]++;
        }

        int cnt = 0, limit = n / k;

        for (const auto& it : mp) {
            if (it.second > limit) {
                cnt++;
            }
        }

        return cnt;
    }
};