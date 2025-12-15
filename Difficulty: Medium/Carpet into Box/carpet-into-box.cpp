class Solution {
  public:
    int solve(long long a, long long b, long long c, long long d) {
        int cnt = 0;
        while (a > c) {
            a /= 2;
            cnt++;
        }
        while (b > d) {
            b /= 2;
            cnt++;
        }
        return cnt;
    }

    int carpetBox(int A, int B, int C, int D) {
        int ans1 = solve(A, B, C, D);
        int ans2 = solve(A, B, D, C);
        return min(ans1, ans2);
    }
};
