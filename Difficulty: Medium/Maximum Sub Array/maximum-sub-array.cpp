// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        long long n = arr.size(), cur = 0, best = -1;
        int l = 0, bl = -1, br = -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0) {
                cur += arr[i];
                if (cur > best) {
                    best = cur;
                    bl = l;
                    br = i;
                } else if (cur == best && br == i - 1) {
                    br++;
                }
            }
            else {
                cur = 0;
                l = i + 1;
            }
        }

        if (best < 0) {
            return vector<int>{-1};
        }

        vector<int> res;
        for (int i = bl; i <= br; i++) {
            res.push_back(arr[i]);
        }
        
        return res;
    }
};