class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size(), total = 0;
        vector<int> len(n, 1), sum(n);

        for(int i = 0; i < n; i++){
            total += arr[i];
            sum[i] = arr[i];
            
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        sum[i] = sum[j] + arr[i];
                    }
                    else if(len[j] + 1 == len[i]){
                        sum[i] = min(sum[i], sum[j] + arr[i]);
                    }
                }
            }
        }

        int L = 0, minLISsum = sum[0];
        for(int i = 0; i < n; i++){
            if (len[i] > L) {
                L = len[i];
                minLISsum = sum[i];
            } else if (len[i] == L) {
                minLISsum = min(minLISsum, sum[i]);
            }
        }

        return total - minLISsum;
    }
};