class Solution {
#define ll long long int
  public:
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        sort(begin(arr), end(arr));
        int n = arr.size();
        
        auto f = [&](int lim) -> ll {
            ll res = 0;
            
            for (int i = 0; i + 2 < n; i++) {
                int j = i + 1, k = n - 1;
                
                while (j < k) {
                    ll sum = arr[i] + arr[j] + arr[k];
                    
                    if (sum > lim) {
                        k--;
                    } else {
                        res += (k - j);
                        j++;
                    }
                }
            }
            
            return res;
        };
        
        return f(r) - f(l - 1);
    }
};