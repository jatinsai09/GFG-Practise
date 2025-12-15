// User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a, a + n);
    vector<int> res(n);
    int l = 0, r = n - 1, flr = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            res[i] = a[r--];
            flr += res[i];
        } else {
            res[i] = a[l++];
            flr -= res[i];
        }
        
        if (flr <= 0) {
            return {-1};
        }
    }
    
    return res;
}
