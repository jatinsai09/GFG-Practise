// Function to find out the number of ways we can place a black and a
// white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m) {
    // write code here
    const long long mod = 1000000007;
    long long k = 1LL * n * m;
    
    long long total = (k * (k - 1)) % mod;
    
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    
    long long attack = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    attack++;
                }
            }
        }
    }
    
    long long ans = (total - attack + mod) % mod;
    
    return ans;
}