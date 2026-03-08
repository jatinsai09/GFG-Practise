class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        vector<int> f(1001,0);
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            f[arr[i]]++;
        }
        
        for(int a = 1; a <= 1000; a++){
            if(f[a] == 0) continue;
            
            for(int b = a; b <= 1000; b++){
                if(f[b] == 0) continue;
                
                int c2 = a*a + b*b;
                int c = sqrt(c2);
                
                if(c*c != c2) continue;
                if(c > 1000) continue;
                
                if(f[c] > 0){
                    if(a == b && f[a] < 2) continue;
                    if(c == a && f[a] < 2) continue;
                    if(c == b && f[b] < 2) continue;
                    return true;
                }
            }
        }
        
        return false;
    }
};