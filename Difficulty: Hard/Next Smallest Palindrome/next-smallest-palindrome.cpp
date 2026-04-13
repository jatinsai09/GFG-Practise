class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
        
        bool all9 = true;
        for (int i = 0; i < n; i++) {
            if (num[i] != 9) {
                all9 = false;
                break;
            }
        }
        
        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }
        
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;
        
        while (i >= 0 && num[i] == num[j]) {
            i--;
            j++;
        }
        
        bool leftSmall = false;
        if (i < 0 || num[i] < num[j]) {
            leftSmall = true;
        }
        
        while (i >= 0) {
            num[j] = num[i];
            i--;
            j++;
        }
        
        if (leftSmall) {
            int carry = 1;
            
            if (n % 2 == 1) {
                num[mid] += carry;
                carry = num[mid] / 10;
                num[mid] %= 10;
                i = mid - 1;
                j = mid + 1;
            } else {
                i = mid - 1;
                j = mid;
            }
            
            while (i >= 0) {
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                
                num[j] = num[i];
                i--;
                j++;
            }
        }
        
        return num;
    }
};