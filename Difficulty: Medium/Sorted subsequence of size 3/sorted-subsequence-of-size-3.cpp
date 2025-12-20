// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        if (n < 3) {
            return {};
        }

        vector<int> leftMin(n), rightMax(n);

        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }

        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        for (int i = 1; i <= n - 2; i++) {
            if (leftMin[i - 1] < arr[i] && arr[i] < rightMax[i + 1]) {
                return {leftMin[i - 1], arr[i], rightMax[i + 1]};
            }
        }

        return {};
    }
};