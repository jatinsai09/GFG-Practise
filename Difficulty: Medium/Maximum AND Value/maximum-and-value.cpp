class Solution {
  public:
    int maxAND(vector<int>& arr) {
        // code here
        int n = arr.size(), res = 0;
        for(int bit = 31; bit >= 0; bit--){
            int temp = res | (1 << bit), cnt = 0;
            
            for(const auto& num: arr){
                if((num & temp) == temp){
                    cnt++;
                }
            }
            if(cnt >= 2){
                res = temp;
            }
        }
        return res;
    }
};