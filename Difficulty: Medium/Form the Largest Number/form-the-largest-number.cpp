// User function template for C++
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        
        sort(begin(arr), end(arr), [&](int a,int b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1 + s2 > s2 + s1;
        });
        
        string res = "";
        for(auto& i: arr){
            res += to_string(i);
        }
        
        if(res[0] == '0'){
            return "0";
        }
        
        return res;
    }
};
