// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
       sort(begin(citations), end(citations));
       int n = citations.size();
       
       for(int i = 0; i < n; i++){
           if(citations[i] >= n - i){
               return n - i;
           }
       }
       return 0;
        // code here
    }
};
