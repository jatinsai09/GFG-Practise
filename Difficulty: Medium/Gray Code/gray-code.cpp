class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        int lim = (1 << n);
        vector<string> res;

        for(int i = 0; i < lim; i++)
        {
            int g = (i ^ (i >> 1));

            string s = "";
            for(int j = n - 1; j >= 0; j--)
            {
                if((g >> j) & 1) s += '1';
                else s += '0';
            }

            res.push_back(s);
        }

        return res;
    }
};