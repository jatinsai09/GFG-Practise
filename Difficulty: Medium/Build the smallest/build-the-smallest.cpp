string buildLowestNumber(string s, int k) {
    // code here.
        int n = s.size();
        if (k >= n) {
            return "0";
        }
        
        string res = "";
        for (int i = 0; i < n; i++) {
            while (k > 0 && !res.empty() && res.back() > s[i]) {
                res.pop_back();
                k--;
            }
            if (res.empty() && s[i] == '0') {
                continue;
            }
            res.push_back(s[i]);
        }
        
        while (k) {
            if (res.empty()) {
                break;
            }
            res.pop_back();
            k--;
        }
        
        int m = res.size(), j = 0;
        while (j < m) {
            if (res[j] != '0') {
                break;
            }
            j++;
        }
        if (j == m) {
            return "0";
        }
        
        return res.substr(j);
}