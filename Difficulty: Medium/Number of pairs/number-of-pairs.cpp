// User function template for C++

class Solution {
#define ll long long int   
  public:
    long long countPairs(vector<int>& arr1, vector<int>& arr2) {
        // code here
        sort(begin(arr2), end(arr2));
        ll res = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for (auto &y: arr2) {
            if (y == 1) {
                c1++;
            } else if (y == 2) {
                c2++;
            } else if (y == 3) {
                c3++;
            } else if (y == 4) {
                c4++;
            }
        }
        
        ll m = arr2.size();
        for (auto& x: arr1) {
            if (x == 1) {
                continue;
            }
            
            int ind = upper_bound(begin(arr2), end(arr2), x) - begin(arr2);
            ll cnt = c1 + (m - ind);
            
            if (x == 2) {
                cnt -= (c3 + c4);
            } else if (x == 3) {
                cnt += c2;
            }
            
            res += cnt;
        }
        
        return res;
    }
};