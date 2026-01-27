// User function template for C++

class Solution {
  public:
    string nextPalin(string N) {
        // complete the function here
        
        int n = N.size();
        if (n <= 2) {
            return "-1";
        }

        int half = n / 2;
        string left = N.substr(0, half);

        if (!next_permutation(left.begin(), left.end())) {
            return "-1";
        }

        string res = left;

        if (n % 2 == 1) {
            res.push_back(N[half]);
        }

        reverse(left.begin(), left.end());
        res += left;

        return res;
    }
};