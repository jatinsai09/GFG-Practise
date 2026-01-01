class Solution {
  public:
    int next(int x) {
        int s = 0;
        while (x) {
            int d = x % 10;
            s += d * d;
            x /= 10;
        }
        return s;
    }
    
    bool isHappy(int x) {
        int slow = x;
        int fast = x;

        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);

        return slow == 1;
    }
    
    int nextHappy(int N) {
        // code here
        int x = N + 1;
        while (true) {
            if (isHappy(x)) {
                return x;
            }
            x++;
        }
    }
};