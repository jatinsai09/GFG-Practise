// User function Template for C++

class Solution {
#define ll long long int    
  public:
    long long int wineSelling(vector<int>& arr, int n) {
        // Code here.
        ll cur = 0, buy = 0, sell = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                arr[i] *= -1;
                int got = min(buy, (ll)arr[i]);
                buy -= got;
                sell += arr[i] - got;
            } else {
                int got = min(sell, (ll)arr[i]);
                sell -= got;
                buy += arr[i] - got;
                
            }
            cur += (sell + buy);
        }
        
        return cur;
    }
};
