class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        
        while(i < n && j < m){
            if(a[i] <= b[j]){
                k--;
                if(k == 0){
                    return a[i];
                }
                i++;
            }
            else{
                k--;
                if(k == 0){
                    return b[j];
                }
                j++;
            }
        }
        
        while(i < n){
            k--;
            if(k == 0){
                return a[i];
            }
            i++;
        }
        
        while(j < m){
            k--;
            if(k == 0){
                return b[j];
            }
            j++;
        }
    }
};
