class Solution {
  public:

    int steppingNumbers(int n, int m) {
        // Code Here
        int res = (n == 0);
        
        for (int i = 1; i <= 9; i++) {
            queue<int> q;
            q.push(i);
            
            while(!q.empty()) {
                int num = q.front();
                q.pop();
                
                if (num > m) {
                    continue;
                }
                
                if (num >= n) {
                    res++;
                }
                
                int last = num % 10;
                if (last > 0) {
                    q.push(num * 10 + (last - 1));
                } 
                if (last < 9) {
                    q.push(num * 10 + (last + 1));
                }
            }
        }
        
        return res;
    }
};
