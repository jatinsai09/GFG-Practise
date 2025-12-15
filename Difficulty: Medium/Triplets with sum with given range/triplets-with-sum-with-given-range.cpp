// User function Template for C++

class Solution {
  public:
    long long countTripletsUtil(int n, int sum, int a[]) {
        // Your code goes here
        long long res = 0;
        for (int i = 0; i + 2 < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                long long s = a[i] + a[j] + a[k];
                if (s <= sum) {
                    res += (k - j);
                    j++;
                }  else {
                    k--;
                }
            }
        }
        
        return res;
    }
    int countTriplets(int Arr[], int N, int L, int R) {
        // code here
        sort(Arr, Arr + N);
        return countTripletsUtil(N, R, Arr) - countTripletsUtil(N, L - 1, Arr);
    }
};