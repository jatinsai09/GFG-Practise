class Solution {
#define ll long long int
  public:
    char nthCharacter(int n) {
        // code here
        ll d = 1, l = 1, cnt = 9;
        
        while (cnt * d < n) {
            n -= cnt * d;
            
            d++;
            cnt *= 10;
            l *= 10;
        }
        
        n--;
        ll ni = n / d, di = n % d;
        
        ll num = l + ni;
        string s = to_string(num);

        return s[di];
    }
};