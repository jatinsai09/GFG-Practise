class Solution {
    #define ll long long 
  public:
    long long jumpingNums(long long n) {
        // code here
        ll res = 0;
        
        for (ll i = 1; i <= 9; i++) {
            queue<ll> q;
            q.push(i);
            
            while (!q.empty()) {
                ll num = q.front();
                q.pop();
                
                if (num > n) {
                    continue;
                }
                
                res = max(res, num);
                
                int last = num % 10;
                if (last > 0) {
                    q.push(num * 10 + last - 1);
                }
                if (last < 9) {
                    q.push(num * 10 + last + 1);
                }
            }
        }
        return res;
    }
};
