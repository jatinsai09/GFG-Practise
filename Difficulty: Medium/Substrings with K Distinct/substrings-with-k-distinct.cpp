//User function template for C++



class Solution
{
  public:
    long long int atMostK(string s, int k) {
        if(k < 0) return 0;
        
        long long int n = s.size(), res = 0;
        int f[26] = {0}, c = 0;
        
        for (int l = 0, r = 0; r < n; r++){
            if(++f[s[r] - 'a'] == 1) c++;
            
            while (c > k){
                if(--f[s[l] - 'a'] == 0) c--;
                l++;
            }
            
            res += (r - l + 1);
        }
        
        return res;  //code here.
    }
    
    
    long long int countSubstr(string s,int k){
        return atMostK(s, k) - atMostK(s, k - 1); 
    }
};
