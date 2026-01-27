string nxtHighUsingAtMostOneSwap(string num) {
    // complete the function here
    int n = num.size();
    int i = n - 2;

    while (i >= 0 && num[i] >= num[i + 1]) {
        i--;
    }

    if (i < 0) {
        return "-1";
    }

    char best = '9' + 1;
    int idx = -1;

    for (int j = i + 1; j < n; j++) {
        if (num[j] > num[i] && num[j] < best) {
            best = num[j];
            idx = j;
        }
    }

    swap(num[i], num[idx]);
    return num;
}