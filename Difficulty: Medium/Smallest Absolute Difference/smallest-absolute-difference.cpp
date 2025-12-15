int kthDiff(int a[], int n, int k) {
    
    sort(a, a + n);
    int l = 0, r = a[n - 1] - a[0], m, res = 0;
    
    while (l <= r) {
        m = l + (r - l) / 2;
        
        int c = 0;
        for (int i = 0, j = 0; j < n; j++) {
            while (a[j] - a[i] > m) {
                i++;
            }
            c += (j - i);
        }
        
        if (c >= k) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}